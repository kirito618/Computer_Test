#include<stdio.h>
int n;
int val[1010],count[1010];
int cnt=0;

void quick_sort(int l,int r){
    if(l>=r) return ;
    int i=l,j=r;
    int k=val[l];
    while(i<j){
        while(j>i&&val[j]>=k){
            j--;
        }
        val[i] = val[j];
        while(i<j&&val[i]<=k){
            i++;
        }
        val[j] = val[i];
    }
    val[i] = k;
    if(l<i-1)
        quick_sort(l,i-1);
    if(r>i-1)
        quick_sort(i+1,r);
}

int main(){
    int x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(count[x]>=1) continue;
        count[x]++;
        val[cnt++] = x;
    }
    quick_sort(0,cnt-1);
    for(x=0;x<cnt;x++) printf("%d ",val[x]);
    putchar('\n');

    return 0;
}
