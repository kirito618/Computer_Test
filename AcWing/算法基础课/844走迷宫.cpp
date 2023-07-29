#include<iostream>
using namespace std;

struct Node{
	int x,y,st;
};

int n,m;
int graph[110][110];
int way[4] = {-1,1,-1,1};
int visited[110][110];
int step;

Node allNodes[10010];
int hh = 0,tt = 0;

void bfs(){
	
	int x1,y1,x2,y2,ts;
	Node one;
	one.x = 1;
	one.y = 1;
	one.st = 0;
	allNodes[tt++] = one;
	visited[1][1] = 1;
	while(hh<tt){
		x1 = allNodes[hh].x;
		y1 = allNodes[hh].y;
		ts = allNodes[hh].st;
		if(x1==n&&y1==m) break; 
		for(int i=0;i<4;i++){
			if(i<2){
				x2 = x1+way[i];	
				y2 = y1;
			}else{
				y2 = y1+way[i];
				x2 = x1;
			}
			if(x1<=0||y2<=0||x2>n||y2>m) continue;
			if(visited[x2][y2]!=1&&graph[x2][y2]!=1){
				Node temp;
				temp.x = x2;
				temp.y = y2;
				temp.st = ts+1;
				allNodes[tt++] = temp;
				visited[x2][y2] = 1;
			}
		}
		hh++; // ³ö¶Ó 
	}
}

int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&graph[i][j]);
			
	bfs();
	printf("%d\n",allNodes[hh].st);
	return 0;
}
