#include<stdio.h>

int p[1010];

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    int N,M,i,j,a,b;
    int cnt;
    scanf("%d%d",&N,&M);
    cnt = N;
    for(i=1;i<=N;i++) p[i] = i;
    for(i=1;i<=M;i++){
        scanf("%d%d",&a,&b);
        if(find(a)!=find(b)){
            p[find(b)] = p[find(a)];
            // Á¬Í¨Êı-1
            cnt--;
        }
    }

    printf("%d\n",cnt-1);

    return 0;
}
