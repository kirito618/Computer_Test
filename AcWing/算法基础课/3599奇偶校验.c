#include<stdio.h>
#include<string.h>

char input[110];
char res[9];
int mi[8];

void method(char x){
    int j=6,cnt=0;
    int n = x;
    while(j>=0){
        if(n>=mi[j]){
            cnt++;
            n-=mi[j];
            res[j] = 1;
        }else{
            res[j] = 0;
        }
        j--;
    }

    if(cnt%2==0){
        res[7]=1;
    }else{
        res[7]=0;
    }
    for(j=7;j>=0;j--){
        printf("%d",res[j]);
    }
    printf("\n");
}

int main(){
    int i,len;
    scanf("%s",input);
    len = strlen(input);
    mi[0] = 1;
    for(i=1;i<8;i++) mi[i] = mi[i-1]*2;

    for(i=0;i<len;i++){
        method(input[i]);
    }

    return 0;
}
