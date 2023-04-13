#include<bits/stdc++.h>
using namespace std;

// ��AC  һ��� 

int N,K;// N:��ϵ����  K:Ҫ���ͨ��ʱ��
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
		// map��value����ǻ����������� ��ô��ʼֵΪ0
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
		//�����Ѿ����������k��ͷ�õ��Ĵ�
		//�����������ҵ����������Ȩ�ص��Ǹ�
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
