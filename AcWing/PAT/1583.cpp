#include<stdio.h>
#include "string.h"
char input[100010];
char all[4] = {' ','P','A','T'};
long long result;
// dp[i][j]��ʾ ����[0,i]����ĸ���ܹ�����״̬j��·����
// ״̬0--->(ͨ��P)״̬1--->(ͨ��A)״̬2--->(ͨ��T)״̬3(AC) 
// ��dp[i][j] = dp[i-1][j](������i���ַ�) + dp[i-1][j-1];
// ��dp[i-1][j-1]�ñ�֤��ǰ�ַ���Ӧ j-1 -> j״̬������ַ� 
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
			// ���ȿ��� �ڲ����ǵ�ǰ�ַ���ǰ�����Ѿ�����j״̬��·�߸��� 
			dp[i][j] = dp[i-1][j];
			// ���ǵ�ǰ�ַ�����ô��һ��״̬����dp[i-1][j-1]
			// �������Ҫͨ��input[i]����j״̬
			// �ñ�֤input[i]������j-1��j״̬������ַ� 
			if(j>=1&&input[i]==all[j]){
				dp[i][j]+=dp[i-1][j-1];
			}
			dp[i][j] = dp[i][j]%1000000007;
		}
	}
	
	printf("%lld\n",dp[len-1][3]);
	return 0;
} 
