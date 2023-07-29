#include<stdio.h>
#include<string.h>

int main(){
    int cnt=0,i,j,t,jin;
    char a[1010],b[1010];
    int res[1010];
    while(scanf("%s %s",a,b)!=EOF){
        i = strlen(a)-1;
        j = strlen(b)-1;
        jin = 0;
        cnt = 0;
        while(i>=0&&j>=0){
            t = (a[i]-'0') + (b[j]-'0') + jin;
            res[cnt++] = t%10;
            jin = t/10;
            i--;j--;
        }
        while(i>=0){
            t = (a[i]-'0')+jin;
            res[cnt++] = t%10;
            jin = t/10;
            i--;
        }
        while(j>=0){
            t = (b[j]-'0')+jin;
            res[cnt++] = t%10;
            jin = t/10;
            j--;
        }
        if(jin!=0){
            res[cnt++] = jin;
        }
        for(i=cnt-1;i>=0;i--) printf("%d",res[i]);
        putchar('\n');
    }

    return 0;
}
