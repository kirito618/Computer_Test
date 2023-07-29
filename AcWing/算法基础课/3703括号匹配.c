#include<stdio.h>
#include<string.h>
char st[110];
int top;

int main(){
    int n,i,len;
    int flag;
    char input[110],t,x;
    //printf("%d %d %d %d",'{','[','(','<');
    scanf("%d",&n);
    while(n--){
        getchar();
        top = 0;
        flag = 1;
        scanf("%s",input);
        len = strlen(input);
        for(i=0;i<len;i++){
            if(input[i]=='['||input[i]=='('||input[i]=='{'||input[i]=='<'){
                // ·ûºÅÈëÕ»
                if(input[i]=='<'||top==0){

                }else{
                    if(st[top]=='<'||input[i]>st[top]){
                        flag = 0;
                        break;
                    }
                }
                st[++top] = input[i];
            }else{
                // Õ»¶¥³öÕ»
                t = st[top--];
                x = input[i];
                if((t=='<'&&x=='>')||(t=='('&&x==')')||(t=='{'&&x=='}')||(t=='['&&x==']')){
                    flag = 1;
                }else{
                    flag = 0;
                    break;
                }
            }
        }
        if(top!=0) flag = 0;
        if(flag==1) puts("YES");
        else puts("NO");
    }

    return 0;
}
