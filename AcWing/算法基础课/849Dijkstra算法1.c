#include<stdio.h>
int dis[510];
int w[510][510];
int ok[510];
int n,m;

int dijkstra(){
    int i,j,t,x;
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    for(i=1;i<=n;i++){
        t = -1;
        // 找到当前没处理的节点中距离最短的
        for(j=1;j<=n;j++){
            if(ok[j]!=1&&(t==-1||dis[t]>dis[j])){
                t = j;
            }
        }
        ok[t] = 1;
        for(j=1;j<=n;j++){
            x = w[t][j]+dis[t];
            dis[j] = x<dis[j]?x:dis[j];
        }
    }
    if(dis[n]==0x3f3f3f3f) return -1;
    return dis[n];
}

int main(){
    int i,j,t,a,b,x;
    scanf("%d %d",&n,&m);
    memset(w,0x3f,sizeof w);
    while(m--){
        scanf("%d %d %d",&a,&b,&t);
        w[a][b] = w[a][b]<t?w[a][b]:t;
    }
    t = dijkstra();
    printf("%d\n",t);
    return 0;
}
