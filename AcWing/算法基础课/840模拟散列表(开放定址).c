#include<stdio.h>
#include<stdlib.h>
int MAX = 0x3f3f3f3f,N = 200020;
int h[200020];

// ���Ŷ�ַ��,���x�����򷵻����ŵ�λ�ã����򷵻���Ӧ�÷ŵ�λ��
int find(int x){
    int i=(x%N+N)%N;
    while(h[i]!=MAX&&h[i]!=x){
        i++;
        if(i==N) i=0;
    }
    return i;
}

int main(){
    char op;
    int N,k,x;
    scanf("%d",&N);
    // ȫ������Ϊ���ֵ����ʾ����ռ�
    memset(h,0x3f,sizeof h);
    while(N--){
        getchar();
        scanf("%c%d",&op,&k);
        if(op=='I'){
            x = find(k);
            h[x] = k;
        }else{
            int x = find(k);
            if(h[x]!=MAX) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
