#include<stdio.h>
#include<string.h>
typedef unsigned long long ull;
ull h[1000010],p[1000010];
ull X = 131;
char P[1000010],S[1000010];
int n,m;

// ��ȡָ���Ӵ���hashֵ 
ull getHash(int a,int b){
	return h[b]-h[a-1]*p[b-(a-1)];
}

int main(){
	int i,j,k;
	ull hashP = 0;
	scanf("%d\n",&n);
	scanf("%s",P+1);
	scanf("%d\n",&m);
	scanf("%s",S+1);
	p[0] = 1;
	// ����P����hashֵ 
	for(i=1;i<=n;i++){
		hashP = hashP*X + P[i];
	}
	for(i=1;i<=m;i++){
		h[i] = h[i-1]*X + S[i];
		p[i] = p[i-1]*X;
	}
	// ö��ÿ������Ϊn���Ӵ�,����hashֵ��P���бȽ�
	// �����,��˵������Ӵ���Pƥ��,�����ʼ�±�
	for(i=1;i+n-1<=m;i++){
		if(getHash(i,i+n-1)==hashP){
			printf("%d ",i-1);
		}
	}
	puts("");
	
	return 0;
}
