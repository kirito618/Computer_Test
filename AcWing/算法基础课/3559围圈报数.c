#include<stdio.h>
int T,N;
int he,val[60],ne[60],cnt;

void add(int v){
	val[cnt] = v;
	ne[cnt-1] = cnt;
	ne[cnt++] = he;
}

int main(){
	int i,j,k,tt,handle;
	scanf("%d",&T);
	while(T--){
		cnt=0,handle=0,tt=0;
		scanf("%d",&N);
		for(i=1;i<=N;i++) add(i);
		for(i=he;handle<N;i=ne[i]){
			tt++;
			if(tt==2){
				j = ne[i];
				printf("%d ",val[j]);
				ne[i] = ne[j];
				tt=0;
				handle++;
			}
		}
		puts("");
	}
	
	
	return 0;
}
