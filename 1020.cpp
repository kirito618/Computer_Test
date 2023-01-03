#include<iostream>
#include<vector> 
using namespace std;
int N;
//order[0]代表的是后序，order[1]代表的是中序
vector<int> order[2];
vector<int> tree[31];
int postIndex[31];
int inIndex[31];
int left_length,right_length;

// s1,e1 分别是后序遍历区间的起始下标和结束下标，后面同理，是中序遍历的 
void dfs(int s1,int e1,int s2,int e2,int level){
	if(s1>e1) return;
	// 后序遍历区间的最后一个值一定是这个子树的根节点 
	int result = order[0][e1];
	// 存入树容器对应层里去 
	tree[level].push_back(result);
	// 进入左子树
	// 左子树在后序遍历的区间的右端点未知，要用左端点下标+长度 -1 
	dfs(s1, s1+inIndex[result]-1-s2,s2,inIndex[result]-1,level + 1);
	// 进入右子树,右子树区间在后序遍历的区间的左端点未知，要用右端点下标 -长度
	dfs(inIndex[result]+e1-e2, e1-1 ,inIndex[result]+1,e2,level + 1);
}


int main(){
	int i,j,k,count;
	cin>>N;
	// 存入后序遍历序列 
	for(i=0;i<N;i++){
		cin>>j;
		// 记录这个点在后序序列中的下标 
		postIndex[j] = i; 
		order[0].push_back(j);
	}
	k = j;
	// 存入中序遍历序列 
	for(i=0;i<N;i++){
		cin>>j;
		// 记录这个点在中序序列中的下标
		inIndex[j] = i;
		order[1].push_back(j);
	}
	
	// 后序遍历的最后一个结果一定是总根节点，所以初始下标该节点的中序下标 
	k = inIndex[k];
	dfs(0,N-1,0,N-1,1);
	count = N;
	for(int level=1;level<=N;level++){
		
		for(int i=0;i<tree[level].size();i++){
			if(count!=N) cout<<" ";
			cout<<tree[level][i];
			count--;
		}
	}
	cout<<endl;
	return 0;
}
