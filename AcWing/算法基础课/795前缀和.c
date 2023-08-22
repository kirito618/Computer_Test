#include<stdio.h>
int sum[100010];

int main(){
	int n,m,i,t,l,r;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		sum[i] = sum[i-1]+t;
	}
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	
	return 0;
}
