#include<iostream>
#include<vector>
using namespace std;

int N,M,C1,C2;
vector<int> neigh[510];
int team[510],graph[510][510],visited[510];
int minDis=100000000,maxTeam=0,minDisCount=0;

void dfs(int cur,int teamNum,int dis){
	if(visited[cur]==1||dis>minDis) return ;
	
	if(cur==C2){
		// µΩ¥Ô÷’µ„
		if(dis<minDis){
			minDisCount = 1;
			maxTeam = teamNum;
			minDis = dis;
		}else if(dis==minDis){
			minDisCount++;
			if(teamNum>maxTeam) maxTeam = teamNum;
		}
		return ;
	}
	visited[cur]=1;
	for(int next:neigh[cur]){
		dfs(next,teamNum+team[next],dis+graph[cur][next]);
	}
	visited[cur]=0;
}

int main(){
	int a,b,c;
	cin>>N>>M>>C1>>C2;
	for(int i=0;i<N;i++) cin>>team[i];
	
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		graph[a][b] = c;
		graph[b][a] = c;
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	
	dfs(C1,team[C1],0);
	cout<<minDisCount<<" "<<maxTeam<<endl;
	return 0;
}
