#include<stdio.h>
int N;
int arr[100010],result[100010],cnt = 0;
int st[100010],top=0;

int main(){
    int i,x;
    scanf("%d",&N);
    st[0] = 100000000;
    for(i = 0;i<N;i++){
        scanf("%d",&arr[i]);
        while(top>0&&st[top]>=arr[i]){
            top--;
        }
        if(top==0){
            result[cnt++] = -1;
        }else{
            result[cnt++] = st[top];
        }
        st[++top] = arr[i];
    }
    for(i=0;i<cnt;i++) printf("%d ",result[i]);
    printf("\n");

    return 0;
}
