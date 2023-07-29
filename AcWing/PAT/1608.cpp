#include<bits/stdc++.h>
using namespace std;

int N,p[10010];
unordered_set<int> nodes[10010];
unordered_set<int> allRoots;

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}


int main(){
	int Q,K,root,a,b,maxIndex=-1;
	int subG;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		scanf("%d%d",&Q,&root);
		maxIndex = max(root,maxIndex);
		for(int i=1;i<Q;i++){
			scanf("%d",&a);
			nodes[root].insert(a);
			maxIndex = max(maxIndex,a);
		}
		allRoots.insert(root);
	}
	
	for(int i=1;i<=maxIndex;i++) p[i] = i;
	subG = maxIndex;
	
	for(int r:allRoots){
		for(int son:nodes[r]){
			if(find(son)!=find(r)){
				p[find(son)] = find(r);
				subG--;
			}
		}
	}
	
	printf("%d %d\n",subG,maxIndex);
	
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		cin>>a>>b;
		if(find(a)==find(b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
