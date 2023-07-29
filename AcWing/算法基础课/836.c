#include<stdio.h>
int n,m;
// 记录每个节点所属集合的祖先节点 
int p[100010];

// 找到x所属集合的祖先节点 
int find(int x){
	if(p[x]!=x){
		p[x] = find(p[x]);
	}
	return p[x];
}

int main(){
	char op;
	int a,b;
	scanf("%d %d\n",&n,&m);
	// 刚开始各自为营 
	int i;
	for(i=1;i<=n;i++) p[i] = i;
	
	for(i=0;i<m;i++){
		scanf("%c %d %d\n",&op,&a,&b);
		//printf("%c %d %d\n",op,a,b);
		if(op=='M'){
			// 将a和b所在集合合并
			p[find(a)] = find(b); 
		}else{
			// 查询操作
			if(find(a)==find(b)) printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
} 
