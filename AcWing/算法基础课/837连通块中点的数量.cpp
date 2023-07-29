#include<stdio.h>
int n,m;
int p[100010],num[100010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	char op[2];
	int a,b;
	scanf("%d%d\n",&n,&m);
	// 各自为营 
	for(int i=1;i<=n;i++){
		p[i] = i;
		num[i] = 1;
	} 
	while(m--){
		scanf("%s",op);
		if(op[0] == 'C'){
			// ab连一条边 
			scanf("%d %d",&a,&b);
			// 将b所在集合连在a的祖先下
			if(find(a)!=find(b)){
				num[find(a)]+=num[find(b)];
				p[find(b)] = find(a);
			}
		}else if(op[1]=='1'){
			// 查询ab是否在一个连通块内 
			scanf("%d %d",&a,&b);
			if(find(a)==find(b)){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}else{
			// 询问a所在连通块中点的数量
			scanf("%d",&a);
			printf("%d\n",num[find(a)]);
		}
	}
	return 0;
}
