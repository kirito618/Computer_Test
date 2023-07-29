#include<stdio.h>
#include<stdlib.h>
// AC!!!
int embed_ind=0;
int head;
int val[100010],next[100010] = {-1};

int M;

// ͷ����� 
void insertHead(int v){
	// �õ���һ���ڵ��±� 
	int q = next[head];
	val[++embed_ind] = v;
	next[embed_ind] = q;
	next[head] = embed_ind;
}

// ɾ��������Ϊk�� 
void deleteK(int k){
	if(k==0){
		// ɾ��ͷ�ڵ�,����һ���㵱ͷ�ڵ�
		int q = next[head];
		next[head] = -1;
		head = q;
		return ;
	}
	int p = next[k];
	next[k] = next[p];
	next[p] = -1;
}

// �ڵ�k���������������� 
void insertAfterK(int k,int v){
	int p = next[k];
	val[++embed_ind] = v;
	next[embed_ind] = p;
	next[k] = embed_ind;
}

int main(){
	char op;
	int a,b,c;
	head = 0;
	scanf("%d\n",&M);
	while(M--){
		scanf("%c",&op);
		if(op=='H'){
			scanf("%d",&a);
			insertHead(a);
		}else if(op=='I'){
			scanf("%d %d",&a,&b);
			insertAfterK(a,b);
		}else if(op=='D'){
			scanf("%d",&c);
			deleteK(c);
		}
		getchar();
	}
	
	int p = next[head];
	while(p!=-1){
		printf("%d",val[p]);
		if(next[p]!=-1) printf(" ");
		p = next[p];
	}
	printf("\n");
	
	return 0;
}
