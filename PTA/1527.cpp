#include<bits/stdc++.h>

int result[1010];
int preorder[1010],inorder[1010],postorder[1010];
int cnt,N;


bool build(int pl,int pr,int il,int ir,int type){
	if(il>ir){
		// 没有节点,那当然可以建二叉树了
		return true;
	}
	// 先序区间的第一个就是根节点 
	int root = preorder[pl];
	int k;
	bool res = true;
	if(type==0){
		// 找到中序遍历中第一次出现该根节点的位置
		// 其左侧是左子树,右侧是右子树 
		for(k=il;k<=ir;k++){
			if(root==inorder[k]){
				break;
			}
		}
		if(k>ir) return false;
	}else{
		// 找到中序遍历中第一次出现该根节点的位置
		// 其左侧是左子树,右侧是右子树 
		for(k=ir;k>=il;k--){
			if(root==inorder[k]){
				break;
			}
		}
		if(k<il) return false;
	}
	if(!build(pl+1,pl+k-il,il,k-1,type)) res = false;
	if(!build(pr-ir+k+1,pr,k+1,ir,type)) res = false;
	
	// 记录后序遍历结果
	postorder[cnt++] = root; 
	return res;
}

using namespace std;
int main(){
	scanf("%d",&N);
	// 输出先序遍历 
	for(int i=0;i<N;i++){
		scanf("%d",&preorder[i]);
		inorder[i] = preorder[i];
	}
	
	// 生成中序序列 
	sort(inorder,inorder+N);
	
	if(build(0,N-1,0,N-1,0)){
		puts("YES");
		cout<<postorder[0];
		for(int i=1;i<cnt;i++){
			cout<<" "<<postorder[i];
		}
		cout<<endl;
	}else{
		// 原本的树不行,那么就按要求进行镜像(左右子树调换) 
		reverse(inorder,inorder+N);
		cnt = 0; 
		if(build(0,N-1,0,N-1,1)){
			puts("YES");
			cout<<postorder[0];
			for(int i=1;i<cnt;i++){
				cout<<" "<<postorder[i];
			}
			cout<<endl;
		}else{
			puts("NO");
		}
	}
	
	return 0;
}
