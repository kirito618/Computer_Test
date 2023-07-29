#include<stdio.h>

int n,m;
int val[100010],ne[100010],he[100010],dis[100010],idx=0;
int q[100010];

// ͷ�巨
void add(int a,int b){
    val[idx] = b;
    ne[idx] = he[a];
    he[a] = idx ++;
}

void bfs(){
    int hh=0,tt=0,t,i,j;
    q[tt++] = 1;
    dis[1] = 0;
    while(hh<=tt){
        t = q[hh++];
        for(i = he[t];i!=-1;i=ne[i]){
            j = val[i];
            if(dis[j]==-1){
                q[tt++] = j;
                dis[j] = dis[t] + 1;
            }
        }
    }

}

int main(){
    int a,b,i,j;
    scanf("%d %d",&n,&m);
    memset(he,-1,sizeof he);
    memset(dis,-1,sizeof dis);
    while(m--){
        scanf("%d %d",&a,&b);
        add(a,b);
    }

    bfs();
    printf("%d\n",dis[n]);

    return 0;
}
