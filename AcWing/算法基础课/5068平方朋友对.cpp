#include<stdio.h>
int n,maxA;
int st[1000010];

int f(int x){
	return x*x/1000;
}

int main(){
	int i,j,k,maxB,cnt=0,flag;
	long long A,B;
	scanf("%d%d",&n,&maxA);
	maxB = (maxA+n)*1000;
	for(B=32;B*B<maxB;B++){
		A = f(B);
		for(i=1;i<n;i++){
			if(f(B+i)!=A+i){
				break;
			}
		}
		if(i==n&&st[A]!=1){
			st[A]=1;
			cnt++;
			printf("%d %d\n",A,B);
		}
	}
	if(cnt==0) puts("No Solution.");
	return 0;
}
