#include<stdio.h>
int n,m;
// ��¼ÿ���ڵ��������ϵ����Ƚڵ� 
int p[100010];

// �ҵ�x�������ϵ����Ƚڵ� 
int find(int x){
	if(p[x]!=x){
		p[x] = find(p[x]);
	}
	return p[x];
}

int main(){
	char op;
	int a,b;
	scanf("%d %d\n",&n,&m);
	// �տ�ʼ����ΪӪ 
	int i;
	for(i=1;i<=n;i++) p[i] = i;
	
	for(i=0;i<m;i++){
		scanf("%c %d %d\n",&op,&a,&b);
		//printf("%c %d %d\n",op,a,b);
		if(op=='M'){
			// ��a��b���ڼ��Ϻϲ�
			p[find(a)] = find(b); 
		}else{
			// ��ѯ����
			if(find(a)==find(b)) printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
} 
