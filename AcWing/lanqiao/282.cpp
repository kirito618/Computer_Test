#include<bits/stdc++.h>

using namespace std;

int N;
int v[300];
// s[i]表示的就是0~i号石的代价和 
int s[300];
// dp[i][j]代表的是将[i,j]内的石子合并在一起的最小代价。 
int dp[300][300];

int main(){
	int x;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>v[i];
		if(i>0) s[i] = s[i-1] + v[i];
		else s[i] = v[i];
	}
	
	// 将i~k化为一堆，将k+1~j化为一堆	
	for(int len=2;len<=N;len++){
		for(int i=0;i+len-1<N;i++){
			x = i+len-1;
			dp[i][x] = 100000000;
			for(int k=i;k<x;k++){
				dp[i][x] = min(dp[i][x],dp[i][k]+dp[k+1][x]+s[x]-s[i-1]); 
			}
		}
	}
	
	cout<<dp[0][N-1]<<endl;
	return 0;
} 
