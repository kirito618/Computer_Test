#include<stdio.h>
#include<string.h>
int val[30],l[30],r[30],h[30],cnt;
int n;

// ���ص�ǰ���ڵ�����������ĸ߶Ȳ� 
int get_balance(int u){
	return h[l[u]]-h[r[u]];
}

// ��ƽ��������в���һ���� 
void insert(int cur,int w){
	if(!cur){
		val[cnt++] = w;
	}else if(w<val[cur]){
		// Ӧ�ò������ 
		insert(l[cur],w);
		if(get_balance(cur)==2){
			if(get_balance(l[cur])==-1){
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
			if(get_balance(l[cur])==-1){
				// ���2,�Ҳ�������ʽ,�������ڵ� 
				L(cur); 
			}else{
				// ���3
				R(r[cur]);
				L(cur);
			}
		}
	}
	// ���µ�ǰ�ڵ�ĸ߶� 
	update(cur);
}

// ����u�ڵ�ĸ߶�(���ڵ�߶�=�����������߶�+1) 
void update(int u){
	h[u] = h[l[u]]<h[r[u]]?h[l[u]]:h[r[u]];
	h[u]++; 
}

// �������� 
void R(int u){
	int l_son = l[u];
	l[u] = r[l_son];
	r[l_son] = u;
	// �����,���߸߶���Ҫ���� 
	update(u),update(l_son);
}

// �������� 
void L(int u){
	int r_son = r[u];
	r[u] = l[r_son];
	l[r_son] = u;
	// �����,���߸߶���Ҫ���� 
	update(u),update(r_son);
}

int main(){
	int i,root=0,w;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&w);
		insert(root,w);
	}
	for(i=0;i<cnt;i++){
		printf(" %d-%d-%d ",val[l[i]],val[i],val[r[i]]);
	}
	return 0;
} 
