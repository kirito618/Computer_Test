#include<bits/stdc++.h>
using namespace std;

int N,V;
int dp[101][101];
int v[101],w[101],s[101];

int main(){
	int maxW,tempW;
	cin>>N>>V;
	for(int i=1;i<=N;i++) cin>>v[i]>>w[i]>>s[i];
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<=V;j++){
			maxW = dp[i-1][j];
			for(int k=1;k<=s[i]&&k*v[i]<=j;k++){
				tempW = dp[i-1][j-k*v[i]]+k*w[i];
				maxW = maxW>tempW?maxW:tempW;
			}
			dp[i][j] = maxW;
		}
	}
	
	cout<<dp[N][V]<<endl;
	return 0;
}
