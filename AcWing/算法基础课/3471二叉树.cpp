#include<stdio.h>
int m,n;

int dfs(int root){
	if(root>n) return 0;
	int l = dfs(root*2);
	int r = dfs(root*2+1);
	return l+r+1;
}

int main(){
	int cnt,l,r,level;
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m==n&&n==0) break;
	//	cnt=dfs(m); ³¬Ê± 
		l=2*m;
		r=2*m+1;
		cnt=1;
		level=1;
		while(r<=n){
			l=2*l;
			r=2*r+1;
			level *= 2;
			cnt+=level;
		}
		if(l<=n) cnt+=n-l+1;
		printf("%d\n",cnt);
	}
	
	return 0;
} 
