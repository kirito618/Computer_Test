#include<iostream>
#include<vector>
using namespace std;
int N,M,S,D;
int minDis = 100000000,minMoney = 100000000;
int map[500][500],cost[500][500];
bool visited[500];
// ���ڴ�����·�� 
//vector<vector<int>> paths;
vector<int> paths;

// ��㣬�յ㣬�ۼƼ�Ǯ���ۼƾ���, ��ʱ���� 
void bfs(int start,int destination,int money,int distance,vector<int> list){
	// ��֦���Ѿ���֮ǰ��·�����ˣ�û��Ҫ�ټ�����ȥ�� 
	if(distance>minDis){	
		return;
	}
	
	if(start == destination){
		// ���������յ�
		if(distance<minDis){
			// �ۼƾ����֮ǰ��̵���������
			minDis = distance;
			minMoney = money;
			paths = list;
		}else if(distance == minDis){
			// �����֮ǰ����̾���һ��������˭�ļ۸����
			if(money < minMoney){
				// Ǯ���٣����£�����·������
				minDis = distance;
			    minMoney = money;
				paths = list;
			}
		}
		return ;
	}
	
	for(int i=0;i<N;i++){
		if(map[start][i]>0 && (!visited[i])){
			// ������ͨ����Ŀ���Ϊ���ʹ��������ߣ����������ݹ�
			visited[i] = true;
			list.push_back(i);
			bfs(i,destination,money+cost[start][i],distance+map[start][i],list);
			list.pop_back();
			visited[i] = false;
		}
	}
	
}

int main(){
	int m,n,dis,co,last,cur;
	vector<int> temp;
	cin>>N>>M>>S>>D;
	// ��ʼ�� 
	for(int i=0;i<M;i++){
	    for(int j=0;j<M;j++){
		    cost[i][j] = -1;
	    }
	    visited[i] = false;
	}
	visited[S] = true;
	// �������� 
	for(int i=0;i<M;i++){
		cin>>m>>n>>dis>>co;
		map[m][n] = map[n][m] = dis;
		cost[m][n] = cost[n][m] = co;
	}
	// �������յ㣬��ô���������·�� 
	if(S==D){
		//cout<<S<<" "<<D<<" 0 0"<<endl;
		cout<<S<<" "<<" 0 0"<<endl;
		return 0;
	}
	bfs(S,D,0,0,temp);
	cout<<S;
	temp = paths;
	for(int i=0;i<temp.size();i++){
		cout<<" "<<temp[i];
	}
	cout<<" "<<minDis<<" "<<minMoney<<endl;
	return 0;
}



/*4 5 3 0
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20*/

