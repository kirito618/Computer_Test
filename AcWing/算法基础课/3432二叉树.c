#include<stdio.h>

int main(){
    int x,y,fx,fy;
    scanf("%d %d",&x,&y);

    // ��Ϊ����������,�и��ڵ��±�Ϊi/2����ȡ�����ص�
    // ��ôÿ����ֵ��ĵ������ĸ��ڵ�,������2
    // ��ô��������й�����,���Ȼ��ĳһ�γ�����x��y��Ϊ���������
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
