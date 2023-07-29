#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[101];
int depthNum[101]; 
int maxDepth = -1;

void dfs(int cur,int depth){
	if(tree[cur].size()==0){
		// 当前是叶子节点
		depthNum[depth]++;
		maxDepth = maxDepth>depth?maxDepth:depth;
		return;
	}
	
	for(int son:tree[cur]){
		dfs(son,depth+1);
	}
}

int main(){
	int N,M,temp;
	int root,son;
	cin>>N>>M;
	// 邻接表建树 
	for(int i=0;i<M;i++){
		cin>>root>>temp;
		for(int j=0;j<temp;j++){
			cin>>son;
			tree[root].push_back(son);
		}
	}
	
	dfs(1,0);
	cout<<depthNum[0];
	for(int i=1;i<=maxDepth;i++) cout<<" "<<depthNum[i];
	cout<<endl;
	
	return 0;
}
