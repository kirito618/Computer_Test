#include<stdio.h>
int ne[100000],cnt[100000];

int main(){
    int h1,h2,ad1,ad2,N,i;
    char val;
    scanf("%d %d %d",&h1,&h2,&N);
    while(N--){
        scanf("%d %c %d",&ad1,&val,&ad2);
        ne[ad1] = ad2;
    }

    for(i=h1;i!=-1;i=ne[i]){
        cnt[i]++;
    }

    for(i=h2;i!=-1;i=ne[i]){
        if(cnt[i]==1){
            printf("%05d\n",i);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}
