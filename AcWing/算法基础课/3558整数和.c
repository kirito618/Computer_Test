#include<stdio.h>
int T,N;
int a[210];

int main(){
	int i,fu,res;
	scanf("%d",&T);
	for(i=1;i<=200;i++) a[i] = a[i-1]+i;
	while(T--){
		fu = 1;
		scanf("%d",&N);
		if(N<0) fu = -1;
		N*= fu; 
		res = a[2*N]-a[N-1];
		res *= fu;
		printf("%d\n",res);
	}
	return 0;
}
