#include<stdio.h>
int m,n;

int gcd(int x,int y){
    int a,b,c;
    a = x; b = y;
    if(x<y){
        a=y;
        b=x;
    }
    c = a%b;
    while(c!=0){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

int main(){
    int t,res1,res2;
    scanf("%d%d",&m,&n);
    t = m>n?m:n;
    res1 = gcd(m,n);
    res2 = m*n/res1;
    printf("%d %d\n",res1,res2);

    return 0;
}
