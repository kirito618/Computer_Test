#include<stdio.h>
#include<string.h>
// 已经AC 

//DP状态机模型 
char input[100010];
char status[4] = {' ','C','O','W'};
int N;
// dp[i][j]表示从i号字符走到j号状态的路数 
long long dp[100010][4];

int main(){
	scanf("%d",&N);
	scanf("%s",input);
	for(int i=N;i>=1;i--){
		input[i] = input[i-1];
	}
	
	for(int i=0;i<=N;i++) dp[i][0] = 1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=3;j++){
			dp[i][j] = dp[i-1][j];
			if(input[i]==status[j]){
				//即当前字符满足从j-1到j的边
				dp[i][j] = dp[i][j] + dp[i-1][j-1];
			}
		}
	}
	printf("%lld\n",dp[N][3]);
	return 0;
}
