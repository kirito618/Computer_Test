#include<stdio.h>
int st[10010],top;

int main(){
	int n,i,j,k;
	char op;
	while(scanf("%d\n",&n)!=EOF){
		top = 0;
		if(n==0) break;
		for(i=0;i<n;i++){
			scanf("%c\n",&op);
			if(op=='P'){
				scanf("%d\n",&k);
				st[++top] = k;
			}else if(op=='O'){
				if(top>0) st[top--];
			}else{
				if(top>0) printf("%d\n",st[top]);
				else puts("E"); 
			}
		}
		puts("");
	}
	
	return 0;
}
