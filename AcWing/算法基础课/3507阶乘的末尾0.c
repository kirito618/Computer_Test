#include<stdio.h>

int n;
long five[15];

void init(){
    int x = 1,i;
    for(i=0;i<15;i++){
        five[i] = x;
        x *= 5;
    }
}

int main(){
    int i=1,res=0;
    scanf("%d",&n);
    init();

    while(five[i]<=n){
        res+=n/five[i];
        i++;
    }
    printf("%d\n",res);
    return 0;
}
