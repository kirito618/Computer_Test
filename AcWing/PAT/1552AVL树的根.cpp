#include<stdio.h>
#include<string.h>
int val[30],l[30],r[30],h[30],cnt;
int n;

// ���ص�ǰ���ڵ�����������ĸ߶Ȳ� 
int get_balance(int u){
	return h[l[u]]-h[r[u]];
}

// ����u�ڵ�ĸ߶�(���ڵ�߶�=�����������߶�+1) 
void update(int u){
	h[u] = h[l[u]]>h[r[u]]?h[l[u]]:h[r[u]];
	h[u]++; 
}

// �������� 
void R(int& u){
	int p = l[u];
	l[u] = r[p];
	r[p] = u;
	// �����,���߸߶���Ҫ���� 
	update(u),update(p);
	u = p;
}

// �������� 
void L(int& u){
	int p = r[u];
	r[u] = l[p];
	l[p] = u;
	// �����,���߸߶���Ҫ���� 
	update(u),update(p);
	u = p;
}

// ��ƽ��������в���һ���� 
void insert(int& cur,int w){
	if(!cur){
		cur = ++cnt;
		val[cur] = w;
	}else if(w<val[cur]){
		// Ӧ�ò������ 
		insert(l[cur],w);
		if(get_balance(cur)==2){
			if(get_balance(l[cur])==1){
				// ���1,���������ʽ,�������ڵ� 
				R(cur); 
			}else{
				// ���3
				L(l[cur]);
				R(cur);
			}
		}
	}else{
		insert(r[cur],w);
		if(get_balance(cur)==-2){
			if(get_balance(r[cur])==-1){
				// ���2,�Ҳ�������ʽ,�������ڵ� 
				L(cur); 
			}else{
				// ���4
				R(r[cur]);
				L(cur);
			}
		}
	}
	// ���µ�ǰ�ڵ�ĸ߶� 
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
