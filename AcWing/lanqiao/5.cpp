#include<bits/stdc++.h>
using namespace std;

// Î´ÄÜAC 
int N,V;
int dp[1001][2001];
int v[2001],w[2001],s[2001];

int main(){
	int maxW,tempW;
	cin>>N>>V;
	for(int i=1;i<=N;i++) cin>>v[i]>>w[i]>>s[i];
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<=V;j++){
			dp[i][j] = dp[i-1][j];
			if(j>=s[i]*v[i]){
				dp[i][j] = max(dp[i][j],dp[i][j-v[i]] - (s[i]-1)*w[i] - dp[i-1][j-s[i]*v[i]]);
			}
		}
	}
	
	cout<<dp[N][V]<<endl;
	return 0;
}
