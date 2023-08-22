#include<stdio.h>
int N,cnt,flag;
int q[1000010];

void dfs(int last,int sum){
	int t;
	if(sum>N) return ;
	else if(sum==N){
		flag = 1;
		for(t=0;t<cnt;t++){
			printf("%d ",q[t]);
		}
		puts("");
		return ;
	}
	q[cnt++] = last+1;
	dfs(last+1,sum+last+1);
	cnt--;
}

int main(){
	int i;
	flag=0;
	scanf("%d",&N);
	for(i=0;i<N-1;i++)
		dfs(i,0);
	if(flag==0) puts("NONE");
	return 0;
} 
