#include<stdio.h>
#include<string.h>

int cnt,res;
char str[1010];
int main(){
    cnt = 0;
    res = 0;
    str[0]='0';
    while(1){
        scanf("%s",str);
        res = strlen(str);
        if(str[res-1]=='.'){
            printf("%d ",res-1);
            break;
        }
        printf("%d ",res);
    }

    return 0;
}
