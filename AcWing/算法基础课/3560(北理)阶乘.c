#include<stdio.h>
int jie[30][30],cnt[30];

void multiply(int last,int cur){
	int i,j,k,jin=0,t=0;
	for(i=0;i<cnt[last];i++){
		k = jie[last][i]*cur+jin;
		jin = k/10;
		jie[cur][t++] = k%10; 
	}
	while(jin!=0){
		jie[cur][t++] = jin%10;
		jin /= 10;
	}
	cnt[cur] = t;
}

int main(){
	int n,i,j;
	jie[0][0]=1;
	cnt[0] = 1;
	for(i=1;i<=30;i++){
		// 高精度乘法 
		multiply(i-1,i);
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&j);
		for(i=cnt[j]-1;i>=0;i--) printf("%d",jie[j][i]);
		puts("");
	}
	return 0;
}
