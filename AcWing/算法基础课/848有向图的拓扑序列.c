#include<stdio.h>
int n,m;
int val[100010],ne[100010],he[100010],idx;
int ru[100010],q[100010];

void add(int a,int b){
    val[idx] = b;
    ne[idx] = he[a];
    he[a] = idx++;
}

void top_sort(){
    int k=n,i,t,x;
    int hh=0,tt=0;
    for(i=1;i<=n;i++){
        if(ru[i]==0){
            q[tt++] = i;
        }
    }

    while(k--){
        t = q[hh++];
        for(i = he[t];i!=-1;i=ne[i]){
            x = val[i];
            ru[x]--;
            if(ru[x]==0){
                q[tt++] = x;
            }
        }
    }

    if(tt==n){
        for(i=0;i<tt;i++) printf("%d ",q[i]);
        printf("\n");
    }else{
        printf("-1\n");
    }

}

int main(){
    int i,a,b;
    for(i=0;i<100010;i++) he[i]=-1;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        add(a,b);
        ru[b]++;
    }
    top_sort();
    return 0;
}
