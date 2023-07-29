#include<stdio.h>

int h[1010];
int M,N;
int flag;

void back_v(int cur){
    if(2*cur<=N) back_v(2*cur);
    if(2*cur+1<=N) back_v(2*cur+1);
    printf("%d ",h[cur]);
}

void check_min(int cur){
    if(flag==0) return ;
    if(2*cur<=N){
        // 查看左孩子是否合理
        if(h[cur]<h[2*cur])
            check_min(2*cur);
        else{
            flag = 0;
        }
    }
    if(2*cur+1<=N){
        // 查看左孩子是否合理
        if(h[cur]<h[2*cur+1])
            check_min(2*cur+1);
        else{
            flag = 0;
        }
    }
}

void check_max(int cur){
    if(flag==0) return ;
    if(2*cur<=N){
        // 查看左孩子是否合理
        if(h[cur]>h[2*cur])
            check_max(2*cur);
        else{
            flag = 0;
        }
    }
    if(2*cur+1<=N){
        // 查看左孩子是否合理
        if(h[cur]>h[2*cur+1])
            check_max(2*cur+1);
        else{
            flag = 0;
        }
    }
}

int main(){
    int i;
    scanf("%d%d",&M,&N);
    while(M--){
        for(i=1;i<=N;i++){
            scanf("%d",&h[i]);
        }
        flag = 1;
        check_min(1);
        if(flag==1){
            printf("Min Heap\n");
        }else{
            flag = 1;
            check_max(1);
            if(flag==1){
                printf("Max Heap\n");
            }else{
                printf("Not Heap\n");
            }
        }
        back_v(1);
        printf("\n");
    }
    return 0;
}
