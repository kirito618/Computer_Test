#include<stdio.h>

int main(){
	int n,t,i,res;
	scanf("%d",&n);
	while(n--){
		res = 0;
		scanf("%d",&t);
		while(t>0){
			if(t%2==1) res++;
			t/=2;
		}
		printf("%d ",res);
	}
	puts("");
	return 0;
}
