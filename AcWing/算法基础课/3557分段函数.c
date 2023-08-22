#include<stdio.h>

int main(){
	int T,i,x;
	double res;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		if(x>=0&&x<=2) res = -1*x+2.5;
		else if(x>2&&x<4) res = 2-1.5*(x-3)*(x-3);
		else res = x/2.0-1.5;
		printf("y=%.1f\n",res);
	}
	
	return 0;
}
