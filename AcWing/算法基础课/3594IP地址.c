#include<stdio.h>
#include<string.h>
char ip[20];

int main(){
    int i,len,n,fu;
    int flag;
    while(scanf("%s",ip)!=EOF){
        len = strlen(ip);
        ip[len]='.';
        flag=1;
        fu=1;
        n=0;
        for(i=0;i<=len;i++){
            if(ip[i]=='-'){
                fu=-1;
            }else if(ip[i]!='.'){
                n = n*10+ip[i]-'0';
            }else if(ip[i]=='.'){
                n = n*fu;
                if(n<0||n>255){
                    flag = 0;
                    break;
                }
                n = 0;
                fu = 1;
            }
        }
        if(flag==1) printf("Yes!\n");
        else printf("No!\n");
    }

    return 0;
}
