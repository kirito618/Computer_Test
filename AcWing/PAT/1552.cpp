#include<iostream>
using namespace std;

// 等等再学学！！！
 

int N,cnt;
// v,l,r模拟树,h存储每个节点的高度 
int v[30],l[30],r[30],h[30];
// 更新x号节点的高度 
void update(int x){
	// x的高度等于它的左右儿子的高度最大值+1 
	h[x] = max(h[l[x]],h[r[x]]) + 1;
}
// 计算x号节点左右子树的高度差 
int sub_height(int x){
	return h[l[x]] - h[r[x]];
}

// 将x号点进行左旋,并返回新的根节点 
int turn_left(int x){
	int p = r[x];
	r[x] = l[p];
	l[p] = x;
	// 先更新儿子,在更新新的根节点 
	update(x); 
	update(p);
	return p;
}

// 将x点进行右旋,并返回新的根节点 
int turn_right(int x){
	// 右旋的话一定是根节点的左儿子当新的根节点 
	int p = l[x];
	// 左儿子成为根节点后，左儿子的右儿子是原来的根节点
	// 原来的根节点的左儿子空出来了，恰好存放新根节点的右儿子 
	l[x] = r[p];
	r[p] = x;
	// 更新二者的高度 先更新儿子,在更新新的根节点 
	update(x);
	update(p);
	return p;
} 

// 插入值为x的节点,并返回新的根节点 
int insert(int root,int x){
	if(root == -1) {
		v[cnt] = x;
		root = cnt++;
	}
	else if(x<v[root]){
		// 按照二叉搜索树的规则应该插入到左子树里
		root = insert(l[root],x);
		if(sub_height(root)==2){
			//左右子树高度差是+2,说明左侧高
			if(sub_height(l[root])==1){
				// 左子树的左子树比右子树高,右旋根节点
				root = turn_right(root); 
			}else{
				// 先左旋左儿子,再右旋根节点
				l[root] = turn_left(l[root]); 
				root = turn_right(root);
			}
		}
	}else{
		// 插右子树
		root = insert(r[root],x);
		if(sub_height(root)==-2){
			//左右子树高度差是-2,说明右侧高
			if(sub_height(r[root])==-1){
				// 右子树的右子树比左子树高,左旋根节点
				root = turn_left(root); 
			}else{
				// 先右旋右儿子,再左旋根节点
				r[root] = turn_right(r[root]); 
				root = turn_left(root);
			}
		}
	}
	update(root);
	return root;
}

int main(){
	// root代表的是当前根节点的下标,是不断在改变的 
	int root = -1; 
	cin>>N;
	for(int i=0;i<N;i++){
		l[i]=-1;
		r[i]=-1;
		v[i]=-1;
	}
	for(int i=0;i<N;i++){
		cin>>v[cnt];
		root = insert(root,v[cnt]);
		cout<<h[root]<<endl;
	}
	cout<<v[root]<<endl;
	return 0;
}
