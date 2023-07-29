#include<stdio.h>
#include<string.h>

// 未AC！！！
int path[5] = {0,-1,1,-1,1};
char g[110][110];
int visited[110][110];
int flag;

int x1,x2,y1,y2,m,n,t1,t2;
int way;

void dfs(int k,int x,int y){
    int i;
    //printf("%d %d\n",x,y);
    if(x<0||y<0||x>=m||y>=n||visited[x][y]==1||g[x][y]=='*') return ;
    if(x==x2&&y==y2){
        flag = 1;
        return ;
    }
    visited[x][y] = 1;
    t1 = x;t2 = y;
    if(way<=2) t1=x+path[way];
    else t2=y+path[way];
    dfs(k,t1,t2);
    if(k>0){
        // 可以转弯,选择一个方向进行转弯
        for(i=1;i<=4;i++){
            if(i==way) continue;
            if(i<=2){
                t1 = x+path[i];
                t2 = y;
            }else{
                t1 = x;
                t2 = y+path[i];
            }
            // 起点可以任意探索
            if(t1>=0&&t2>=0&&t1<m&&t2<n){
                way = i;
                dfs(k-1,t1,t2);
            }
        }
    }
    visited[x][y] = 0;
}

int main(){
    int T,i,j,k,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        getchar();
        memset(visited,0,sizeof visited);
        for(i=0;i<m;i++){
            scanf("%s",g[i]);
        }
        scanf("%d%d%d%d%d",&k,&y1,&x1,&y2,&x2);
        x1--;x2--;y1--;y2--;
        flag = 0;
        for(i=1;i<=4;i++){
            if(i<=2){
                x = x1+path[i];
                y = y1;
            }else{
                x = x1;
                y = y1+path[i];
            }
            // 起点可以任意探索
            if(x>=0&&y>=0&&x<m&&y<n){
                way = i;
                dfs(k,x,y);
            }
        }
        if(flag==1) puts("yes");
        else puts("no");
    }
    return 0;
}
