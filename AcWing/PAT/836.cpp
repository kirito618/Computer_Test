#include<bits/stdc++.h>
using namespace std;
int p[100010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int n,m,a,b;
	char opt;
	cin>>n>>m;
	// 让它们自己和自己是一个集合 
	for(int i=1;i<=n;i++) p[i] = i;
	
	for(int i=0;i<m;i++){
		cin>>opt>>a>>b;
		if(opt=='M'){
			// 合并两集合 
			if(find(a)!=find(b)){
				// 二者不在同一个集合里
				p[find(a)] = find(b); 
			}
		}else if(opt == 'Q'){
			// 查询两者是否在同一个集合里面
			if(find(a)!=find(b)) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	return 0;
}
