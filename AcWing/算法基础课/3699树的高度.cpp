#include<iostream>
#include<vector>
using namespace std;

int N,M;
int st[10010];
vector<int> g[10010];
int res=0;

void dfs(int cur,int dis){
	res = max(dis,res);
	for(int j:g[cur]){
		if(st[j]!=1){
			st[j]=1;
			dfs(j,dis+1);
		}	
	}
}

int main(){
	int i,j,u,v;
	scanf("%d%d",&N,&M);
	for(i=0;i<N-1;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	st[M]=1;
	dfs(M,0);
	printf("%d\n",res);
	return 0;
}
