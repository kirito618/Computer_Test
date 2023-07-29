#include<stdio.h>

int main(){
    int i,flag;
    int n;
    while(scanf("%d",&n)!=EOF){
        flag = 0;
        for(i=1;i<n;i++){
            if(i*i%n==0){
                flag = 1;
                break;
            }
        }
        if(flag==1){
            puts("Yes");
        }else{
            puts("No");
        }
    }

    return 0;
}
