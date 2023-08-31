#include<stdio.h>
int heap[1010],n,maxH,minH;
int route[1010],cnt,visited[1010];

void dfs(int cur){
    int son = 0,i;
    if(visited[cur]==1) return ;
    visited[cur]=1;
    route[cnt++] = heap[cur];
    if(cur*2+1<=n){
        if(heap[cur*2+1]>heap[cur]) maxH = 0;
        if(heap[cur*2+1]<heap[cur]) minH = 0;
        dfs(cur*2+1);
        son = 1;
    }
    if(cur*2<=n){
        if(heap[cur*2]>heap[cur]) maxH = 0;
        if(heap[cur*2]<heap[cur]) minH = 0;
        dfs(cur*2);
        son = 1;
    }
    if(son==0){
        // 说明是个叶子节点
        for(i=0;i<cnt;i++) printf("%d ",route[i]);
        puts("");
    }
    cnt--;
}

int main(){
    int i;
    maxH=1, minH=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&heap[i]);
    dfs(1);
    if(maxH) puts("Max Heap");
    else if(minH) puts("Min Heap");
    else puts("Not Heap");
    return 0;
}
