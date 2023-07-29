#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> hobbyList[1010];
vector<int> neighbor[1010];
unordered_map<int,int> roots; 
vector<int> results;
int handled[1010];

int p[1010];
int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

bool comp2(int a,int b){
	return a<b;
}

bool comp(int a,int b){
	return roots[a]>roots[b];
} 

int main(){
	int maxHobby=-1,K,h;
	int subG,temp;
	char x;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%c",&K,&x);
		for(int j=1;j<=K;j++){
			scanf("%d",&h);
			// 将当前用户放入对应的爱好列表中去 
			hobbyList[h].push_back(i);
			maxHobby = max(maxHobby,h);
		}
	}
	for(int i=1;i<=N;i++) p[i] = i;
	for(int i=1;i<=maxHobby;i++){
		if(hobbyList[i].size()==0) continue;
		sort(hobbyList[i].begin(),hobbyList[i].end(),comp2);
		int root = hobbyList[i][0];
		for(int j=1;j<hobbyList[i].size();j++){
			neighbor[root].push_back(hobbyList[i][j]);
		}
	}
	
	subG = N;
	for(int i=1;i<=N;i++){
		if(neighbor[i].size()==0) continue;
		for(int x:neighbor[i]){
			if(find(x)!=find(i)){
				p[find(x)] = find(i);
				subG--;
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		int root = find(i);
		if(!roots.count(root)){
			roots[root] = 1;
			results.push_back(root);
		}else{
			roots[root]++;
		}
	}
	
	sort(results.begin(),results.end(),comp);
	
	cout<<subG<<endl;
	
	cout<<roots[results[0]];
	for(int i=1;i<results.size();i++){
		cout<<" "<<roots[results[i]];
	}
	cout<<endl;
	
	return 0;
}
