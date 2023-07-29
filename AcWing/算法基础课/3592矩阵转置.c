#include<stdio.h>

int arr[110][110];

int main(){
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&arr[i][j]);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }



    return 0;
}
