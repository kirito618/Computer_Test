#include<stdio.h>
int n,m;
typedef struct edge{
	int a;
	int b;
	int val;
}edge; 
edge E[200010];
int idx[200010];
int p[200010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
} 

void quick_sort(int l,int r){
	int t = idx[l];
	int ll = l,rr = r;
	while(ll<rr){
		while(ll<rr&&E[idx[rr]].val>=E[idx[t]].val) rr--;
		idx[ll] = idx[rr];
		while(ll<rr&&E[idx[ll]].val<=E[idx[t]].val) ll++;
		idx[rr] = idx[ll];
	}
	idx[ll] = t;
	if(l<ll) quick_sort(l,ll-1);
	if(r>ll) quick_sort(ll+1,r);
}

void Kruskal(){
	int i,res=0,cnt=0;
	// 将边进行排序 
	quick_sort(0,m-1);
	for(i=0;i<m;i++) printf("%d ",E[idx[i]].val);
	puts("");
	for(i=1;i<=n;i++) p[i]=i;
	for(i=0;i<m;i++){
		// 若左右不连通 
		int a = E[idx[i]].a,b=E[idx[i]].b,w=E[idx[i]].val;
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
		idx[i]=i;
	}
	Kruskal();
	
	return 0;
}
