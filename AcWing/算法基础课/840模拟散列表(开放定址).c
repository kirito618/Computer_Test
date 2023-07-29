#include<stdio.h>
#include<stdlib.h>
int MAX = 0x3f3f3f3f,N = 200020;
int h[200020];

// 开放定址法,如果x存在则返回其存放的位置，否则返回其应该放的位置
int find(int x){
    int i=(x%N+N)%N;
    while(h[i]!=MAX&&h[i]!=x){
        i++;
        if(i==N) i=0;
    }
    return i;
}

int main(){
    char op;
    int N,k,x;
    scanf("%d",&N);
    // 全部设置为最大值，表示空余空间
    memset(h,0x3f,sizeof h);
    while(N--){
        getchar();
        scanf("%c%d",&op,&k);
        if(op=='I'){
            x = find(k);
            h[x] = k;
        }else{
            int x = find(k);
            if(h[x]!=MAX) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
