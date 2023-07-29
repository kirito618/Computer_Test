#include<stdio.h>

int n,cnt;
int res[10010];

void init(){
    int i,j;
    int flag;
    for(i=11;i<=10000;i+=10){
        flag = 1;
        for(j=2;j<i;j++){
            if(i%j==0) flag=0;
        }
        if(flag==1)
            res[cnt++] = i;
    }
}

int main(){
    int i=0,flag;
    init();
    while(scanf("%d",&n)!=EOF){
        flag = 1;
        if(res[0]>=n) flag=0;
        for(i=0;res[i]<n&&i<cnt;i++){
            printf("%d ",res[i]);
        }
        if(flag==0) printf("-1");
        printf("\n");
    }
    return 0;
}
