#include<stdio.h>
int p[1010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int n,m,x,y,i,j,res;
	while(scanf("%d%d",&n,&m)!=EOF){
		res = n;
		for(i=1;i<=n;i++) p[i]=i;
		for(i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			if(find(x)!=find(y)){
				p[find(x)] = p[find(y)];
				res--;
			}
		}
//		printf("%d\n",res);
		if(res==1) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
