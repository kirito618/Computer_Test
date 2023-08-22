#include<stdio.h>
#include<string.h>
char input[100010];
int h[100010],p[100010],P=131;

// 得到[l,r]子串的hash值 
int getHash(int l,int r){
	return h[r]-h[l-1]*p[r-(l-1)]; 
}

int main(){
	int m,n,l1,r1,l2,r2,i,j;
	scanf("%d%d",&n,&m);
	// 有效下标从1开始 
	scanf("%s",input+1);
	// 预处理两个数组
	p[0]=1;
	for(i=1;i<=n;i++){
		p[i] = p[i-1]*P;
		h[i] = h[i-1]*P+input[i];
	} 
	while(m--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(getHash(l1,r1)==getHash(l2,r2)) puts("Yes");
		else puts("No");
	} 
	
	return 0;
}
