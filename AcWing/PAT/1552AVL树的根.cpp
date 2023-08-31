#include<stdio.h>
#include<string.h>
int val[30],l[30],r[30],h[30],cnt;
int n;

// 返回当前根节点的左右子树的高度差 
int get_balance(int u){
	return h[l[u]]-h[r[u]];
}

// 更新u节点的高度(根节点高度=左右子树最大高度+1) 
void update(int u){
	h[u] = h[l[u]]>h[r[u]]?h[l[u]]:h[r[u]];
	h[u]++; 
}

// 右旋操作 
void R(int& u){
	int p = l[u];
	l[u] = r[p];
	r[p] = u;
	// 换完后,二者高度需要更新 
	update(u),update(p);
	u = p;
}

// 左旋操作 
void L(int& u){
	int p = r[u];
	r[u] = l[p];
	l[p] = u;
	// 换完后,二者高度需要更新 
	update(u),update(p);
	u = p;
}

// 向平衡二叉树中插入一个点 
void insert(int& cur,int w){
	if(!cur){
		cur = ++cnt;
		val[cur] = w;
	}else if(w<val[cur]){
		// 应该插入左侧 
		insert(l[cur],w);
		if(get_balance(cur)==2){
			if(get_balance(l[cur])==1){
				// 情况1,左侧链条形式,右旋根节点 
				R(cur); 
			}else{
				// 情况3
				L(l[cur]);
				R(cur);
			}
		}
	}else{
		insert(r[cur],w);
		if(get_balance(cur)==-2){
			if(get_balance(r[cur])==-1){
				// 情况2,右侧链条形式,右旋根节点 
				L(cur); 
			}else{
				// 情况4
				R(r[cur]);
				L(cur);
			}
		}
	}
	// 更新当前节点的高度 
	update(cur);
}

int main(){
	int i,root=0,w;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&w);
		insert(root,w);
	}
	printf("%d\n",val[root]);
	return 0;
} 
