#include<stdio.h>
int m,n;
int cnt=0;
int res[20];

// cur:当前处理数字的序号
void dfs(int sum,int cur){
    if(cur>n+1) return ;
    int i=m;
    if(sum==m){
        cnt++;
        //for(i=1;i<cur;i++) printf("%d ",res[i]);
        //printf("\n");
        return ;
    }

    i = m-sum;
    i = i>res[cur-1]?res[cur-1]:i;
    for(;i>=1;i--){
        res[cur] = i;
        dfs(sum+i,cur+1);
    }
}

int main(){
    while(scanf("%d %d",&m,&n)!=EOF){
        cnt = 0;
        res[0] = m+1;
        dfs(0,1);
        printf("%d\n",cnt);
    }
    return 0;
}
