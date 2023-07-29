#include<stdio.h>

int n,m;
int w[510][510],st[510];
int dis[510];

void prim(){
    int res=0;
    int i,j,t;
    memset(dis,0x3f,sizeof dis);
    for(i=0;i<n;i++){
        t = -1;
        for(j=1;j<=n;j++){
            // 找到未确定的最小dis值点
            if(st[j]!=1&&(t==-1||dis[t]>dis[j])){
                t = j;
            }
        }

        if(i!=0 && dis[t]==0x3f3f3f3f){
            printf("impossible\n");
            return ;
        }

        if(i!=0) res += dis[t];
        for(j=1;j<=n;j++) dis[j] = dis[j]<w[t][j]?dis[j]:w[t][j];
        st[t] = 1;
    }
    printf("%d\n",res);
}

int main(){
    int a,b,v,i,j;
    scanf("%d%d",&n,&m);
    memset(w,0x3f,sizeof w);
    while(m--){
        scanf("%d%d%d",&a,&b,&v);
        w[a][b] = w[a][b]<v?w[a][b]:v;
        w[b][a] = w[a][b];
    }
    prim();

    return 0;
}
