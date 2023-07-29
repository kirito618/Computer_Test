#include<stdio.h>

int N;
int val[110],l[110],r[110];
int cnt=0,root;

void insert(int fa,int cur,int x){
    int fl=0,fr = 0;
    if(cnt==0){
        val[cnt++] = x;
        printf("-1\n");
        return ;
    }
    if(cur==-1){
        // ÕÒµ½²åÈëÎ»ÖÃ
        if(val[fa]<=x){
            r[fa] = cnt;
        }else{
            l[fa] = cnt;
        }
        val[cnt++]=x;
        printf("%d\n",val[fa]);
        return ;
    }
    //printf("%d\n",cur);
    if(x<=val[cur]) insert(cur,l[cur],x);
    else insert(cur,r[cur],x);
}

int main(){
    int i,a;
    scanf("%d",&N);
    memset(l,-1,sizeof l);
    memset(r,-1,sizeof r);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        insert(0,0,a);
    }

    return 0;
}
