#include<iostream>
#include<vector>
using namespace std;
int N,M;
vector<int> sons[110];
int level_num[110];
int maxNum=1,maxLevel=1;

void dfs(int cur,int level){
	level_num[level]++;
	if(level_num[level]>maxNum){
		maxLevel = level;
		maxNum = level_num[level];
	}
	if(sons[cur].size()!=0){
		for(int son:sons[cur]){
			dfs(son,level+1);
		}
	}
}

int main(){
	int root,k,t;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>root>>k;
		for(int j=0;j<k;j++){
			cin>>t;
			sons[root].push_back(t);
		}
	}
	
	dfs(1,1);
	cout<<maxNum<<" "<<maxLevel<<endl;
	
	return 0;
}
