#include<stdio.h>
int n,k,wrong;
int p[50010],handled[50010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int op,x,y;
	scanf("%d %d\n",&n,&k);
	for(int i=1;i<=n;i++) p[i] = i;
	while(k--){
		scanf("%d %d %d",&op,&x,&y);
		if(x>n||y>n){
			wrong++;
			continue;
		} 
		if(op==1){
			// X与Y是同类 
			if(handled[x]&&handled[y]){
				if(find(x)!=find(y)){
					wrong++;
				}
			}else if(handled[x]){
				p[find(y)] = find(x);
				handled[y] = 1;
			}else{
				p[find(x)] = find(y);
				handled[x] = 1;
			}
		}else if(op==2){
			// X吃Y 
			if(x==y||find(x)==find(y)){
				wrong++;
			}else{
				
			}
		}
	}
	printf("%d\n",wrong);
	return 0;
}
