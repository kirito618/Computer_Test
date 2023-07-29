#include<stdio.h>
char P[100010],S[100010],ne[100010];
int n,m;

int main(){
    int i,j;
    scanf("%d\n%s",&n,P+1);
    scanf("%d\n%s",&m,S+1);
    ne[0] = 0;
    ne[1] = 0;
    // 初始化next数组
    // 从2开始是因为只有长度为2以上才会有前后缀
    for(i=2,j=0;i<=n;i++){
        while(j>0&&P[j+1]!=P[i]){
            j = ne[j];
        }
        if(P[j+1]==P[i]) j++;
        ne[i] = j;
    }

    for(i=1,j=0;i<=m;i++){
        while(j>0&&P[j+1]!=S[i]) j = ne[j];
        if(P[j+1]==S[i]) j++;
        if(j==n){
            // 找到了一种匹配位置,即已经匹配了n位字符
            printf("%d ",i-n);
            // 更新位置
            j = ne[j];
        }
    }

    return 0;
}
