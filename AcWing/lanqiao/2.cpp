#include<bits/stdc++.h>

using namespace std;
int N,V;

// 1������dp�ⷨ 
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


// 2���Ż��ռ�  ��������еȼ۱��Σ�ʹ�ռ���һά
int dp[1001];
int weight[1001];
int wealth[1001];

int main(){
	cin>>N>>V;
	for(int i=1;i<=N;i++) cin>>weight[i]>>wealth[i];
	
	for(int i=1;i<=N;i++){
		// j��V��ʼ�����Ӻ���ǰ��
		// ��Ϊ����Ҫ��dp[i-1][j]��dp[i-1][j-weight[i]]���ȼ۱���
		// ������ù�������,��ôÿ���µ�һ��,dp�������¼�Ķ�����һ��Ľ��
		// ������Ҫ�õ�����һ���ͬһ�У�������ǰ���е�����
		// ���ԴӺ���ǰ�������Ա�֤����Ҫ�õ������ݻ�û�б����£���������һ������� 
		for(int j=V;j>=weight[i];j--)
			dp[j] = max(dp[j],dp[j-weight[i]]+wealth[i]);
	}
	
	
	cout<<dp[V]<<endl;
	
	return 0;
}
 
