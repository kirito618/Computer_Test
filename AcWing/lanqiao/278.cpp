#include<bits/stdc++.h>

using namespace std;
int N,M;
int A[101];
int dp[101][10001];
int f[10001];

// һάdp
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>A[i];
	
	// ��n������������Ϊ0�����ķ���ֻ��һ��  ����ɶҲ���� 
	f[0] = 1;
	
	for(int i=0;i<N;i++){
		for(int j=M;j>=A[i];j--){
			// f[j] ��Ӧ�ľ��Ƕ�άdp�е� dp[i-1,j]
			// ��ʽ����dp[i-1,j] += dp[i-1,j-A[i]]
			// ��ô��ʱdp[i-1,j] ��ֵ��������Ҫ��� dp[i,j]��ֵ  
			f[j] += f[j-A[i]];
		}
	} 
	
	cout<<f[M]<<endl;
	return 0;
} 


// ��άdp 
//int main(){
//	cin>>N>>M;
//	for(int i=0;i<N;i++) cin>>A[i];
//	
//	// ��ʼ�� 
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
