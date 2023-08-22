#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct edge{
	int a;
	int b;
	int val;
}edge; 
edge E[200010];
int n,m;
int p[200010];

bool cmp(edge a,edge b){
	return a.val<b.val;
}

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
} 

void Kruskal(){
	int i,res=0,cnt=0;
	// 将边进行排序 
	sort(E,E+m,cmp);
//	for(i=0;i<m;i++) printf("%d ",E[idx[i]].val);
//	puts("");
	for(i=1;i<=n;i++) p[i]=i;
	for(i=0;i<m;i++){
		// 若左右不连通 
		int a = E[i].a,b=E[i].b,w=E[i].val;
		a = find(a),b=find(b); 
		if(a!=b){
			p[a] = b;
			res+=w;
			cnt++;
		}
	}
	if(cnt!=n-1) puts("impossible");
	else printf("%d\n",res);
}

int main(){
	int i,u,v,w;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		E[i].a=u,E[i].b=v,E[i].val=w;
	}
	Kruskal();
	
	return 0;
}
