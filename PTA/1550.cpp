#include<bits/stdc++.h>
using namespace std;

int N;
int tree[1010];
int com_tree[1010];
int pnt;

// 按中序遍历 将二叉搜索树的每个值填入完全二叉树 
void inorder(int root){
	// 左子树
	if(2*root<=N){
		inorder(2*root);
	}
	// 设置根节点 
	com_tree[root] = tree[pnt++];
	// 右子树 
	if(2*root+1<=N){
		inorder(2*root+1);
	}
}


int main(){
	cin>>N;
	for(int i=1;i<=N;i++) cin>>tree[i];
	
	// 利用二叉搜索树的特点,中序遍历是递增的 
	sort(tree+1,tree+N+1);
	
	pnt = 1;
	inorder(1);
	
	cout<<com_tree[1];
	for(int i=2;i<pnt;i++) cout<<" "<<com_tree[i];
	cout<<endl;
	
	return 0;
}
