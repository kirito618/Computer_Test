#include<stdio.h>
#include<math.h>
// 记录权值
int w[2010],v[2010][2010];
int dp[2010][8010];
int n,m,q;
int val[2010],ne[2010],he[2010],idx = 0;
int u,c;
int maxValue = -1;

void dfs(int cur,int cost,int value){
    int i;
    if(cost>c) return ;
    printf("%d\n",cur);
    maxValue = maxValue>value?maxValue:value;
    for(i=he[cur];i!=-1;i=ne[i]){
        dfs(val[i],cost+v[cur][val[i]],value+w[val[i]]);
    }
}

// 头插法
void add(int a,int b){
    val[idx] = b;
    ne[idx] = he[a];
    he[a] = idx++;
}

int main(){
    int i,j,a,b,d,temp;
    memset(he,-1,sizeof he);
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i = 1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&d);
        add(a,b);
        v[a][b] = d;
    }
    while(q--){
        maxValue = -1;
        scanf("%d %d",&u,&c);
        // 先初始化,每个节点不花任何代价能获得的最大价值就是它自身的价值
        for(a=1;a<=n;a++) dp[a][0] = w[a];
        for(a=1;a<=c;a++){
            for(b=1;b<=n;b++){
                dp[b][a] = dp[b][a-1];
                for(d=he[b];d!=-1;d=ne[d]){
                    temp = 0;
                    j = val[d];
                    if(v[b][j]<=a)
                        temp = dp[j][a-v[b][j]]+w[b];
                    dp[b][a] = dp[b][a]>temp?dp[b][a]:temp;
                }
            }
        }

        //dfs(u,0,w[u]);
        printf("%d\n",dp[u][c]);
    }

    return 0;
}
