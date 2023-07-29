#include<bits/stdc++.h>

using namespace std;
int N,V;

// 1、朴素dp解法 
//int dp[1001][1001];
//int weight[1001];
//int wealth[1001];
//
//int main(){
//	cin>>N>>V;
//	for(int i=1;i<=N;i++) cin>>weight[i]>>wealth[i];
//	
//	for(int i=1;i<=N;i++){
//		for(int j=0;j<=V;j++){
//			dp[i][j] = dp[i-1][j];
//			if(j>=weight[i]){
//				dp[i][j] = max(dp[i][j],dp[i-1][j-weight[i]]+wealth[i]);
//			}
//		}
//	}
//	
//	
//	cout<<dp[N][V]<<endl;
//	
//	return 0;
//}


// 2、优化空间  将代码进行等价变形，使空间变成一维
int dp[1001];
int weight[1001];
int wealth[1001];

int main(){
	cin>>N>>V;
	for(int i=1;i<=N;i++) cin>>weight[i]>>wealth[i];
	
	for(int i=1;i<=N;i++){
		// j从V开始，即从后往前走
		// 因为我们要对dp[i-1][j]和dp[i-1][j-weight[i]]做等价变形
		// 如果利用滚动数组,那么每到新的一轮,dp数组里记录的都是上一层的结果
		// 而我们要用的是上一层的同一列，或者是前几列的数据
		// 所以从后往前遍历可以保证我们要用到的数据还没有被更新，即还是上一层的数据 
		for(int j=V;j>=weight[i];j--)
			dp[j] = max(dp[j],dp[j-weight[i]]+wealth[i]);
	}
	
	
	cout<<dp[V]<<endl;
	
	return 0;
}
 
