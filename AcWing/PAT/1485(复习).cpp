#include<iostream>
using namespace std;

int N,M,K;
int graph[1010][1010];
int p[1010];//p[i]表示i号点的连通图祖先
// 递归查找x节点的祖先节点 
int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
} 

int main(){
	int a,b,c,num,t;
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	for(int i=0;i<K;i++){
		num = N;
		cin>>c;
		for(int i=1;i<=N;i++) p[i]=i;
		for(int i=1;i<=N;i++){
			if(i==c){
				num--;
				continue;
			} 
			for(int j=1;j<=N;j++){
				if(graph[i][j]!=1||j==c) continue;
				if(find(i)!=find(j)){
					p[find(i)] = p[j];
					num--;
				}
			}
		}
		cout<<num-1<<endl;
	}
	
	return 0;
} 
