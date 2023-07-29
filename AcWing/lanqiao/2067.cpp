#include<iostream>

using namespace std;

int dp[100][31];
int N,M;
int main(){
	cin>>N>>M;
	for(int i=1;i<=N;i++) dp[i][1] = 1;
	for(int j=1;j<=M;j++) dp[1][j] = 1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(i%2==0&&j%2==0) dp[i][j] = 0;
		}
	}
	
	for(int i=2;i<=N;i++){
		for(int j=2;j<=M;j++){
			if(i%2==0&&j%2==0) continue;
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	
	cout<<dp[N][M]<<endl;
	
	return 0;
}
