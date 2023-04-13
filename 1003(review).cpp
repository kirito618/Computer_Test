#include<iostream>
#include<vector>
using namespace std;

int N,M,C1,C2;
// ��¼��ͼ  ֵΪi��j�ľ���  emergency��ʶÿ�����еľ�Ԯ�������� 
int map[500][500],emergency[500];
vector<int> nearly[500];
// ��ʶÿ�������Ƿ��Ѿ����� 
bool visited[500];
// ��¼����㵽�õ����̾��� 
int minDis[500];
int minDistance=10000000000000,maxEmergency=0,minDisCount = 0;

void dfs(int be,int en,int cur,int dis,int emer){
	if(visited[cur]||dis>minDistance) return;
	visited[cur] = true;
	if(cur==en){
		//����Ŀ�ĵ���
		if(dis<minDistance){
			minDistance = dis;
			minDisCount = 1;
			maxEmergency = emer;
		}else if(dis==minDistance){
			minDisCount++;
			maxEmergency = emer>maxEmergency?emer:maxEmergency;
		}
	}
	for(int xx:nearly[cur]){
		if(!visited[xx]){
			dfs(be,en,xx,dis+map[cur][xx],emer+emergency[xx]);
			visited[xx] = false;
		}
	}
}



int main(){
	int x,y,dis;
	cin>>N>>M>>C1>>C2;
	for(int i=0;i<N;i++){
		cin>>emergency[i];
	}
	for(int i=0;i<M;i++){
		cin>>x>>y>>dis;
		map[x][y] = dis;
		map[y][x] = dis;
		nearly[x].push_back(y);
		nearly[y].push_back(x);
	}
	dfs(C1,C2,C1,0,emergency[C1]);
	cout<<minDisCount<<" "<<maxEmergency<<endl;
	
	return 0;
} 
