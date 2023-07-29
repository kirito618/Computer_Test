#include<stdio.h>

int p[1000000];
int arr[1000000];

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    int i,j;
    int n,m,res,t;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(i=0;i<m;i++){
            scanf("%d",&arr[i]);
            p[i] = i;
        }
        res = m;
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(j==i) continue ;
                t = arr[i]&arr[j];
                if(t==0){
                    //printf(" %d %d ",arr[i],arr[j]);
                    if(find(i)!=find(j)){
                        p[find(i)] = find(j);
                        res--;
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
