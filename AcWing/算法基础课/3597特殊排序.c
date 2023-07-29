#include<stdio.h>

int N;
int arr[1010];

void quick_sort(int l,int r){
    if(l>=r) return ;
    int k = arr[l];
    int i=l,j=r;
    while(i<j){
        while(i<j&&arr[j]>=k) j--;
        arr[i] = arr[j];
        while(i<j&&arr[i]<=k) i++;
        arr[j] = arr[i];
    }
    arr[i] = k;
    if(l<i-1)
        quick_sort(l,i-1);
    if(r>i+1)
        quick_sort(i+1,r);
}
int main(){
    int i,m=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
        m = arr[m]>arr[i]?m:i;
    }
    if(N==1){
        printf("%d\n-1\n",arr[m]);
        return 0;
    }
    printf("%d\n",arr[m]);
    arr[m] = -1;
    quick_sort(0,N-1);
    for(i=1;i<N;i++) printf("%d ",arr[i]);
    putchar('\n');

    return 0;
}
