#include<stdio.h>

int dp[30];

int main(){
    int N,i,j,max_step;
    scanf("%d",&N);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(i=3;i<=N;i++){
        for(j=1;j<=3;j++){
            dp[i] = dp[i]+dp[i-j];
        }
    }
    printf("%d\n",dp[N]);
    return 0;
}
