#include<stdio.h>
#include<string.h>
// �Ѿ�AC 

//DP״̬��ģ�� 
char input[100010];
char status[4] = {' ','C','O','W'};
int N;
// dp[i][j]��ʾ��i���ַ��ߵ�j��״̬��·�� 
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
				//����ǰ�ַ������j-1��j�ı�
				dp[i][j] = dp[i][j] + dp[i-1][j-1];
			}
		}
	}
	printf("%lld\n",dp[N][3]);
	return 0;
}
