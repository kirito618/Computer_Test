#include<stdio.h>

int n,m;
int heap[100010];
int cnt;

void down(int cur){
    int t = cur;
    // �����������ӱȵ�ǰ��С
    if(cur*2<=cnt&&heap[cur*2]<heap[t]){
        t = 2*cur;
    }
    // ���Һ������Һ��ӱȵ�ǰ��С
    if((cur*2+1)<=cnt&&heap[cur*2+1]<heap[t]){
        t = 2*cur+1;
    }
    // ��С���Ǹ��㲻�Ǹ��ڵ㣬˵�����ڵ������⣬��Ҫ��λ��
    if(t!=cur){
        heap[0] = heap[t];
        heap[t] = heap[cur];
        heap[cur] = heap[0];
        // �ݹ�ʹ�ýڵ��³�
        down(t);
    }
}


int main(){
    int i;
    scanf("%d %d",&n,&m);

    for(i=1;i<=n;i++){
        scanf("%d",&heap[i]);
    }
    cnt = n;

    // ������ʼ��
    for(i=n/2;i>=1;i--) down(i);

    while(m--){
        // ͷ�ڵ�Ϊ��ǰ������Сֵ
        printf("%d ",heap[1]);
        // ɾ��ͷ�ڵ㣬�������ǰѵ�ǰ�������һ��ֵ�ù���ֱ�Ӹ��ǵ����ڵ�
        heap[1] = heap[cnt--];
        // ����down��������֤�ѽṹ����
        down(1);
    }
    printf("\n");

    return 0;
}
