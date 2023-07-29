#include<bits/stdc++.h>

using namespace std;
int N;

int inorder[40];
int postorder[40];
// 存储后序遍历中元素在中序遍历里对应的下标 
unordered_map<int,int> post_in_mid;
// 存储每个节点的左右子树的根节点 
unordered_map<int,int> l_son,r_son;

// 层序遍历队列 
int q[40];

// 递归建树,返回值为根节点 
int build(int il,int ir,int pl,int pr){
	// 每个根节点都是这个子树区间的后序遍历的最后一个值 
	int root = postorder[pr];
	// 取得根节点在中序遍历中的下标 
	int k = post_in_mid[root];
	if(il<k){
		// 说明存在左子树
		// pl+(k-1-il) 是 因为无论是中序还是后序，子树节点个数是一样的
		// 那么区间长度也是一样的，是推导出来的 
		l_son[root] = build(il,k-1,pl,pl+(k-1-il));
	}
	if(k<ir){
		// 存在右子树
		r_son[root] = build(k+1,ir,pl+(k-1-il)+1,pr-1); 
	}
	return root; 
}

// 宽度优先搜索 
void bfs(int root){
	// 首尾指针 
	int hh=0,tt=0;
	int t;
	q[0] = root;
	while(hh<=tt){
		// 拿到当前队首的根节点 取完后队首指针后移 
		t = q[hh++];
		// 如果左子树map里有key值为当前根节点
		// 说明该节点有左子树 
		if(l_son.count(t)) q[++tt] = l_son[t];
		if(r_son.count(t)) q[++tt] = r_son[t];
	}
	
	cout<<q[0];
	for(int i=1;i<N;i++) cout<<" "<<q[i];
	cout<<endl;
} 

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>postorder[i];
	for(int i=0;i<N;i++){
		cin>>inorder[i];
		// 记录下标 
		post_in_mid[inorder[i]] = i;
	}
	
	int root = build(0,N-1,0,N-1);
	
	// 层序遍历 输出结果 
	bfs(root);
	
	return 0;
}
