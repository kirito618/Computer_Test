#include<stdio.h>

int main(){
    int x,y,fx,fy;
    scanf("%d %d",&x,&y);

    // 因为是满二叉树,有父节点下标为i/2向下取整的特点
    // 那么每次让值大的点变成它的父节点,即除以2
    // 那么如果二者有公共点,则必然在某一次除法后x和y均为这个公共点
    while(x>0&&y>0){
        if(x>y){
            x = x/2;
        }else if(x<y){
            y = y/2;
        }else{
            printf("%d\n",x);
            break;
        }
    }


    return 0;
}
