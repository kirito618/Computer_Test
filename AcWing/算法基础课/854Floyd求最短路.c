#include<stdio.h>
#include<string.h>
int g[210][210];
int n,m,q,maxNum = 0x3f3f3f3f;

void floyd(){
	int i,j,k,dis;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				dis = g[i][k]+g[k][j];
				g[i][j] = g[i][j]<dis?g[i][j]:dis;
			}	  
}

int main(){
	int i,j,k;
	scanf("%d%d%d",&n,&m,&q);
	memset(g,0x3f,sizeof g);
	for(i=1;i<=n;i++) g[i][i]=0;
	while(m--){
		scanf("%d%d%d",&i,&j,&k);
		g[i][j] = k<g[i][j]?k:g[i][j];
	}
	floyd();
	while(q--){
		scanf("%d%d",&i,&j);
		if(g[i][j]>maxNum/2) puts("impossible");
		else printf("%d\n",g[i][j]);
	}
	return 0;
} 
