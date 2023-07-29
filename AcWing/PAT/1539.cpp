#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,S;
vector<int> sons[110];
vector<int> result[110];
vector<int> tempVec;
int v[110];
int cnt;

bool comp(vector<int> a,vector<int> b){
	int k=0;
	int m = min(a.size(),b.size());
	while(k<m-1){
		if(a[k]!=b[k]) break;
		k++;
	}
	if(k==0) return true;
	if(a[k]>b[k]) return true;
	return false;
}

void dfs(int cur,int dis){
	if(sons[cur].size()==0){
		// 是叶子节点
		if(dis==S){
			result[cnt++] = tempVec;
		}
	}else{
		for(int son:sons[cur]){
			tempVec.push_back(v[son]);
			dfs(son,dis+v[son]);
			tempVec.pop_back();
		}
	}
}

int main(){
	int temp,root,son;
	cin>>N>>M>>S;
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
	for(int i=0;i<M;i++){
		cin>>root>>temp;
		for(int j=0;j<temp;j++){
			cin>>son;
			sons[root].push_back(son);
		}
	}
	tempVec.push_back(v[0]);
	dfs(0,v[0]);
	sort(result,result+cnt,comp);
	for(int i=0;i<cnt;i++){
		cout<<result[i][0];
		for(int j=1;j<result[i].size();j++) cout<<" "<<result[i][j];
			cout<<endl;
	}
	
	return 0;
} 
