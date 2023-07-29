#include<bits/stdc++.h>
using namespace std;
int N,V;

//1、朴素dp解法 
int dp[1001][1001];
int weight[1001];
int wealth[1001];

int main(){
	int maxW,temp,tempW;
	cin>>N>>V;
	for(int i=1;i<=N;i++) cin>>weight[i]>>wealth[i];
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<=V;j++){
			dp[i][j] = dp[i-1][j];
			if(j>=weight[i]){
				// dp[i][j] = max(dp[i-1][j],dp[i-1][j-1*weight[i]]+wealth[i],....)
				// dp[i][j-weight[i]] = max(dp[i-1][j-weight[i],dp[i-1][j-2*weight[i]]+wealth[i]+...)
				// 则有 dp[i][j] = max(dp[i][j],dp[i][j-weight[i]]+wealth[i]);
				dp[i][j] = max(dp[i][j-weight[i]]+wealth[i],dp[i][j]);
			}
		}
	}
	cout<<dp[N][V]<<endl;
	return 0;
}


