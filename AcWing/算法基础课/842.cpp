#include<iostream>
using namespace std;

int n,cnt;
int result[8],visited[8];

void dfs(int cur){
	if(cur==n+1){
		// 已经放好一种组合
		for(int i=1;i<cur;i++) cout<<result[i]<<" ";
		cout<<endl;
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(visited[i] == 0){
			visited[i] = 1;
			result[cur] = i;
			dfs(cur+1);
			visited[i] = 0;
		}
	}
}


int main(){
	cin>>n;
	dfs(1);
	
	return 0;
}
