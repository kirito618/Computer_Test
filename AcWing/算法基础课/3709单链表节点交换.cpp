#include<stdio.h>

int N,cnt;
int val[110],ne[110]; 

// 交换链表下标为a和b的两个单元 
void swap(int a,int b){
	int t = ne[b];
	ne[b] = a;
}

int main(){
	int i,a,b,j,k;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&val[i]);
		ne[i-1] = i;
	}
	ne[N] = -1;
	i = 0;
	while(cnt<=N){
		if(N-cnt>=2){
			// 当前点紧邻的两个节点 
			a = ne[i];
			b = ne[a];
			ne[a] = ne[b];
			ne[b] = a;
			ne[i] = b;
			i = a;
			cnt += 2;
		}else{
			i++;
			cnt++;
		}
	}
	
	for(i=ne[0];i!=-1;i=ne[i]){
		printf("%d ",val[i]);
	}
	puts("");
	return 0;
} 
