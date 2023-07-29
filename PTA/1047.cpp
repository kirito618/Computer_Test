#include<bits/stdc++.h>
using namespace std;

bool comp(string a,string b){
	return a<b;
}

int N,K;
vector<string> stu_map[2600];
int main(){
	string name;
	int C,course;
//	cin>>N>>K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		cin>>name;
		scanf("%d",&C);
		for(int j=0;j<C;j++){
//			cin>>course;
			scanf("%d",&course);
			stu_map[course].push_back(name);
		}
	}
	
	for(int i=1;i<=K;i++){
		if(stu_map[i].size()==0||stu_map[i].size()==1) continue;
		sort(stu_map[i].begin(),stu_map[i].end(),comp);
	}
	
	for(int i=1;i<=K;i++){
//		cout<<i<<" "<<stu_map[i].size()<<"\n";
		printf("%d %d\n",i,stu_map[i].size());
		if(stu_map[i].size()==0) continue;
		for(string temp:stu_map[i]){
//			cout<<temp<<endl;
			printf("%s\n",temp.c_str());
		}
	}
	
	return 0;
}
