#include<bits/stdc++.h>
using namespace std;
int N,M,K,temp,a,b,min_index;
int other_index;
double Nc,Nt;

set<int> all_points;
set<int> sets[50];
double results[2000];
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>K;
		for(int j=0;j<K;j++){
			cin>>temp;
			sets[i].insert(temp);
		}
	}
	
	int count1 = 0;
	cin>>K;
	for(int i=0;i<K;i++){
		// 输入要查验的两个集合的序号a和b 
		cin>>a>>b;
		a--;
		b--;
		
		for(int x:sets[a]) all_points.insert(x);
		for(int x:sets[b]) all_points.insert(x);
		
		Nt = all_points.size();
		Nc = sets[a].size() + sets[b].size() - Nt;
		results[i] = Nc/Nt;
		all_points.clear();
	}

	for(int i=0;i<K;i++){
		printf("%.1f%\n",results[i]*100);
	}
	return 0;
}
