#include<stdio.h>
#include<string.h>
typedef unsigned long long ull;
ull h[1000010],p[1000010];
ull X = 131;
char P[1000010],S[1000010];
int n,m;

// 获取指定子串的hash值 
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
	// 计算P串的hash值 
	for(i=1;i<=n;i++){
		hashP = hashP*X + P[i];
	}
	for(i=1;i<=m;i++){
		h[i] = h[i-1]*X + S[i];
		p[i] = p[i-1]*X;
	}
	// 枚举每个长度为n的子串,将其hash值与P进行比较
	// 若相等,则说明这个子串与P匹配,输出起始下标
	for(i=1;i+n-1<=m;i++){
		if(getHash(i,i+n-1)==hashP){
			printf("%d ",i-1);
		}
	}
	puts("");
	
	return 0;
}
