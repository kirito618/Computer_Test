#include<stdio.h>
int n,m;
int he[150010],ne[150010],val[150010],w[150010],cnt;

void add(int x,int y,int z){
	val[cnt] = y;
	w[cnt] = z;
	ne[cnt] = he[x];
	he[x] = cnt++;
}

int main(){
	int i,j,k,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",)
	}
	
	return 0;
}
