#include<stdio.h>
#include "string.h"
char input[100010];
char all[4] = {' ','P','A','T'};
long long result;
// dp[i][j]表示 考虑[0,i]个字母，能够到达状态j的路线数
// 状态0--->(通过P)状态1--->(通过A)状态2--->(通过T)状态3(AC) 
// 则dp[i][j] = dp[i-1][j](不考虑i号字符) + dp[i-1][j-1];
// 且dp[i-1][j-1]得保证当前字符对应 j-1 -> j状态所需的字符 
long long dp[100010][4];

int main(){
	scanf("%s",input);
	int len = strlen(input);
	for(int i=len;i>0;i--){
		input[i] = input[i-1];
	}
	len++;
	input[0]=' ';
	dp[0][0] = 1;
	for(int i=1;i<=len;i++){
		for(int j=0;j<=3;j++){
			// 首先考虑 在不考虑当前字符的前提下已经到达j状态的路线个数 
			dp[i][j] = dp[i-1][j];
			// 考虑当前字符，那么上一个状态就是dp[i-1][j-1]
			// 并且如果要通过input[i]到达j状态
			// 得保证input[i]正好是j-1到j状态所需的字符 
			if(j>=1&&input[i]==all[j]){
				dp[i][j]+=dp[i-1][j-1];
			}
			dp[i][j] = dp[i][j]%1000000007;
		}
	}
	
	printf("%lld\n",dp[len-1][3]);
	return 0;
} 
