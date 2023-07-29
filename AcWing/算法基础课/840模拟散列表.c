#include<stdio.h>
#include<stdlib.h>

int MAX = 100010;
int h[100010],val[100010],ne[100010],idx=0;

// �����������ϣ��ͻ,ͷ�巨
void insert_link(int x){
    // ֱ��ȡ��õ����λ��
    int i = (x%MAX+MAX)%MAX;
    val[idx] = x;
    ne[idx] = h[i];
    h[i] = idx++;
}

// �����������Ƿ����Ԫ��
int find_link(int x){
    // ֱ��ȡ��õ����λ��
    int i = (x%MAX+MAX)%MAX;
    // ȡ������ͷ�ڵ�
    for(i = h[i];i!=-1;i=ne[i]){
        if(val[i]==x){
            return 1;
        }
    }
    return 0;
}

int main(){
    char op;
    int N,k;
    scanf("%d",&N);
    memset(h,-1,sizeof h);
    while(N--){
        getchar();
        scanf("%c%d",&op,&k);
        if(op=='I') insert_link(k);
        else{
            if(find_link(k)==1) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
