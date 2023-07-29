#include<stdio.h>
int N = 10000010;
// s[i] 表示[1,i]中素数的个数
short int is_prime[10000010];
int s[10000010];

int main(){
    int a,b;
    int i,j,res;
    for(i=1;i<=N;i++) is_prime[i] = 1;
    s[0] = 0;
    s[1] = 1;
    for(i=2;i*i<=N;i++){
        if(is_prime[i]!=0){
            for(j=i*i;j<=N;j+=i){
                is_prime[j]=0;
            }
        }
    }
    for(i=1;i<=N;i++) s[i] = s[i-1]+is_prime[i];

    while(scanf("%d %d",&a,&b)!=EOF){
        res = (b-a+1)-(s[b]-s[a-1]);
        printf("%d\n",res);
    }

    return 0;
}
