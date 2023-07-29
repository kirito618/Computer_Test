#include<iostream>
using namespace std;

int queen[10];
int n;
bool check(int cur){
	for(int i=1;i<cur;i++){
		if(queen[i]==queen[cur]||abs(i-cur)==abs(queen[i]-queen[cur])){
			return false;
		}
	}
	return true;
}

void dfs(int cur){
	if(cur==n+1){
		for(int i=1;i<=n;i++){
			int j=1;
			while(j<=n){
				if(j==queen[i]) cout<<"Q";
				else cout<<".";
				j++;
			}
			cout<<endl;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		queen[cur]=i;
		if(check(cur)){
			dfs(cur+1);
		}
	}
}

int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}
