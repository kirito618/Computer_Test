#include<bits/stdc++.h>
using namespace std;
// 看了并查集的课，大致有了些想法，可以把连通的城市看作一个连通子图
// 那么通过并查集我们可以找出有多少个子图，多个子图练成一条线，就是最少要修的通路数
// 也就是子图数-1
int N,M,K;
int p[1010];
vector<int> graph[1010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int a,b,c,subG;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=0;i<K;i++){
		// 如果城市c被攻占了? 还剩下几个连通子图呢 
		scanf("%d",&c);
		subG = N-1;
		for(int j=1;j<=N;j++) p[j] = j;
		for(int j=1;j<=N;j++){
			if(j==c) continue;
			for(int k:graph[j]){
				if(k==c) continue;
				if(find(k)!=find(j)){
					// 二者合并 
					p[find(k)] = find(j);
					// 连通图个数-1 
					subG--;
				}
			}
		}
		printf("%d\n",subG-1);
	}
	
	return 0;
} 
