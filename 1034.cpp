#include<bits/stdc++.h>
using namespace std;

// 已AC  一遍过 

int N,K;// N:关系个数  K:要求的通话时间
map<string,int> weightAll;
map<string,unordered_set<string>> neighbors;
map<string,int> haveUse;
map<string,unordered_set<string>> groups;
map<string,int> groupLen;
set<string> keys;
vector<string> results;

bool comp(string a,string b){
	return a<b;
}

void dfs(string from,string cur){
	if(haveUse[cur]==1) return;
	haveUse[cur] = 1;
	for(string nei:neighbors[cur]){
		groups[from].insert(nei);
		dfs(from,nei);
	}
}

int main(){
	string name1,name2;
	int time,tempMax;
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>name1>>name2>>time;
		// map的value如果是基本数据类型 那么初始值为0
		weightAll[name1] += time;
		neighbors[name1].insert(name2);
		weightAll[name2] += time;
		neighbors[name2].insert(name1);
		keys.insert(name1);
		keys.insert(name2);
	}
	
	for(string k: keys){
		if(haveUse[k]==1) continue;
		dfs(k,k);
		//现在已经生成了这个k打头得到的簇
		//接下来就是找到簇里面最大权重的那个
		tempMax = 0;
		string headName="";
		int allW = 0;
		for(string ne:groups[k]){
			allW += weightAll[ne];
			if(tempMax<weightAll[ne]){
				tempMax = weightAll[ne];
				headName = ne;
			}
		}
		
		allW = allW/2;
		
		if(allW>K&&groups[k].size()>2){
			groupLen[headName] = groups[k].size();
			results.push_back(headName);
		}
	}
	
	sort(results.begin(),results.end(),comp);
	cout<<results.size()<<endl;
	for(string na:results){
		cout<<na<<" "<<groupLen[na]<<endl;
	}
	return 0;
}
