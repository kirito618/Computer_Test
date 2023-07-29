#include<iostream>
using namespace std;
int K;
int nums[10010];
// dp[i]标识以第i个元素为结尾的子序列的最大和 
int dp[10010];
int endIndex,maxSum=-99999999;
int res1,res2;
int fu;

int main(){
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>nums[i];
		if(nums[i]<0) fu++;
	}
	if(fu==K){
		cout<<0<<" "<<nums[0]<<" "<<nums[K-1]<<endl;
		return 0;
	}
	// 初始状态 
	dp[0] = nums[0];
	maxSum = dp[0];
	res2 = nums[0];
	for(int i=1;i<K;i++){
		dp[i]=max(dp[i-1]+nums[i],nums[i]);
		if(dp[i]>maxSum){
			endIndex = i;
			res2 = nums[i];
			maxSum = dp[i];
		}
	}
	
	while(endIndex>=1&&dp[endIndex-1]>=0){
		endIndex--;
	}
	
	res1 = nums[endIndex];
	cout<<maxSum<<" "<<res1<<" "<<res2<<endl;
	
	return 0;
}
