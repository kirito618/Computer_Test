#include<stdio.h>
#include<string.h>
char A[100010],B[100010],res[100010];

void add(){
    int lenA = strlen(A);
    int lenB = strlen(B);
    int i=lenA-1,j=lenB-1,jin=0,cur,cnt=0;
    
    while(i>=0&&j>=0){
        cur = (A[i]-'0')+(B[j]-'0')+jin;
        jin = cur/10;
        cur %= 10;
        res[cnt++] = cur+'0';
        i--,j--;
    }
    
    while(i>=0){
        cur = A[i]-'0'+jin;
        jin = cur/10;
        cur = cur%10;
        res[cnt++] = '0'+ cur;
        i--;
    } 
    while(j>=0){
        cur = B[j]-'0'+jin;
        jin = cur/10;
        cur = cur%10;
        res[cnt++] = '0'+ cur;
        j--;
    }
    if(jin!=0) res[cnt++]='0'+jin;
    for(i=cnt-1;i>=0;i--) printf("%c",res[i]);
    puts("");
}

int main(){
    scanf("%s\n%s",A,B);
    add();
    return 0;
}
