#include<string.h>
#include<stdio.h>
int len;
char a[6],b[6];
int visited[1000];

void quick_sort(int l,int r){
    if(l<=r) return ;
    int k = a[l];
    int x = l,y = r;
    while(x<r){
        while(y>x&&a[y]>=k){
            y--;
        }
        a[x] = a[y];
        while(x<y&&a[x]<=k){
            x++;
        }
        a[y] = a[x];
    }
    a[x] = k;
    quick_sort(l,x-1);
    quick_sort(x+1,r);
}

void dfs(int cur){
    int i;
    if(cur==len+1){
        // 已经得到一种方案
        for(i = 1;i<=len;i++){
            printf("%c",b[i]);
        }
        printf("\n");
        return ;
    }
    for(i=0;i<len;i++){
        if(visited[a[i]]==0){
            b[cur] = a[i];
            visited[a[i]] = 1;
            dfs(cur+1);
            visited[a[i]] = 0;
        }
    }
}

int main(){
    memset(visited,0,sizeof visited);
    scanf("%s",a);
    len = strlen(a);
    quick_sort(0,len-1);
    dfs(1);
    return 0;
}
