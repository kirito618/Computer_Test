#include<stdio.h>
#include<string.h>

// dp[i][j]表示s1串的第i个为结尾,s2串的第j个为结尾的最大公共字串长度。
int dp[110][110];
int max_len=0,max_i=0;

int main(){
    char s1[110],s2[110];
    scanf("%s %s",s1,s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i,j;
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if(s1[i]==s2[j]){
                if(i>0&&j>0)
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = 1;
            }else{
                dp[i][j] = 0;
            }
            if(dp[i][j]>=max_len){
                max_len = dp[i][j];
                max_i = i;
            }
        }
    }
    printf("%d\n",max_len);
    for(i=max_i-max_len+1;i<=max_i;i++) printf("%c",s1[i]);
    printf("\n");
    return 0;
}
