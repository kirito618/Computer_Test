#include<bits/stdc++.h>

using namespace std;
int N,M;
int A[101];
int dp[101][10001];
int f[10001];

// 一维dp
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>A[i];
	
	// 从n个数里挑出和为0的数的方案只有一种  就是啥也不挑 
	f[0] = 1;
	
	for(int i=0;i<N;i++){
		for(int j=M;j>=A[i];j--){
			// f[j] 对应的就是二维dp中的 dp[i-1,j]
			// 下式就是dp[i-1,j] += dp[i-1,j-A[i]]
			// 那么此时dp[i-1,j] 的值就是我们要求的 dp[i,j]的值  
			f[j] += f[j-A[i]];
		}
	} 
	
	cout<<f[M]<<endl;
	return 0;
} 


// 二维dp 
//int main(){
//	cin>>N>>M;
//	for(int i=0;i<N;i++) cin>>A[i];
//	
//	// 初始化 
//	for(int i=0;i<N;i++) dp[i][0] = 1;
//	for(int j=1;j<=M;j++){
//		if(A[0]==j){
//			dp[0][j] = 1;
//		}
//	}
//	
//	for(int i=1;i<N;i++){
//		for(int j=1;j<=M;j++){
//			dp[i][j] = dp[i-1][j];
//			if(j>=A[i]){
//				dp[i][j] += dp[i-1][j-A[i]];
//			}
//		}
//	}
//	
//	cout<<dp[N-1][M]<<endl;
//	return 0;
//} 
