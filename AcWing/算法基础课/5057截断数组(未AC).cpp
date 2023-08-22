#include<stdio.h>
int n,p;
int res[100010];

int main(){
	int i,j,k,a,b;
	int max_res = 0;
	scanf("%d%d",&n,&p);
	res[0]=0;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		res[i] = res[i-1] + k;
	}
//	for(i=1;i<=n-1;i++){
//		a = res[i]%p;
//		b = (res[n]-res[i])%p;
//		k = a+b;
//		if(k>max_res) max_res = k;
//	}
	
	for(i=1;i<=n-1;i++){
		for(j=0;i+j<=n;j++){
			a = res[i]%p;
			b = (res[n]-res[i+j-1])%p;
			k = a+b;
			if(k>max_res) max_res = k;
		}
	}
	printf("%d\n",max_res);
	
	return 0;
}
