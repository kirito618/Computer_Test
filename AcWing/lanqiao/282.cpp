#include<bits/stdc++.h>

using namespace std;

int N;
int v[300];
// s[i]��ʾ�ľ���0~i��ʯ�Ĵ��ۺ� 
int s[300];
// dp[i][j]������ǽ�[i,j]�ڵ�ʯ�Ӻϲ���һ�����С���ۡ� 
int dp[300][300];

int main(){
	int x;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>v[i];
		if(i>0) s[i] = s[i-1] + v[i];
		else s[i] = v[i];
	}
	
	// ��i~k��Ϊһ�ѣ���k+1~j��Ϊһ��	
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
