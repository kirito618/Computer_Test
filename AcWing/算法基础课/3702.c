#include<stdio.h>
#include<string.h>

int main(){
    char x[110],y[110];
    char res[110];
    int len1,len2,i,j,t;
    int cnt = 0;
    while(scanf("%s%s",x,y)!=EOF){
        len1 = strlen(x);
        len2 = strlen(y);
        i = len1-1;
        j = len2-1;
        cnt = 0;
        while(i>=0&&j>=0){
            t = 0;
            if(x[i]>='A'&&x[i]<='Z'){
                t=(x[i]-'A'+10);
            }else if(x[i]>='0'&&x[i]<='9'){
                t=(x[i]-'0');
            }
            if(y[j]>='A'&&y[j]<='Z'){
                t+=(y[j]-'A'+10);
            }else if(y[j]>='0'&&y[j]<='9'){
                t+=(y[j]-'0');
            }
            t = t%16;
            if(t>=10){
                res[cnt++] = (t%10)+'A';
            }else{
                res[cnt++] = t +'0';
            }
            i--;
            j--;
        }
        while(i>=0){
            res[cnt++] = x[i--];
        }
        while(j>=0){
            res[cnt++] = y[j--];
        }

        for(i=cnt-1;i>=0;i--){
            printf("%c",res[i]);
        }
        printf("\n");
    }



    return 0;
}
