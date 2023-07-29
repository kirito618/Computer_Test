#include<stdio.h>

int l[100010],r[100010];
int f[100010];

void insert(int v){
    int i=0;
    while(i!=-1){
        if(v>i){
            if(r[i]==0){
                r[i] = v;
                f[v] = i;
                break;
            }
            i = r[i];
        }else{
            if(l[i]==0){
                l[i] = v;
                f[v] = i;
                break;
            }
            i = l[i];
        }
    }
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    scanf("%d",&j);
    for(i=0;i<n;i++){
        scanf("%d",&j);
        insert(j);
    }
    for(i=1;i<=n;i++){
        printf("%d ",f[i]);
    }
    printf("\n");
    return 0;
}
