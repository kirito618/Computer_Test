#include<stdio.h>

int cnt,tt;
// insert_k[i]��ŵ�i������Ԫ�ص������±�
// heap_k[i]���i��Ԫ�صĲ������
// heap[i]���i��Ԫ��ֵ
int heap[100010],insert_k[100010],heap_k[100010];

void swap_heap(int x,int y){
    heap[0] = heap[x];
    heap[x] = heap[y];
    heap[y] = heap[0];
    insert_k[0] = insert_k[heap_k[x]];
    insert_k[heap_k[x]] = insert_k[heap_k[y]];
    insert_k[heap_k[y]] = insert_k[0];
    heap_k[0] = heap_k[x];
    heap_k[x] = heap_k[y];
    heap_k[y] = heap_k[0];
}

void down(int u){
    int k = u;
    if(2*u<=cnt&&heap[2*u]<heap[k]) k = 2*u;
    if(2*u+1<=cnt&&heap[2*u+1]<heap[k]) k = 2*u+1;
    if(k!=u){
        swap_heap(k,u);
        down(k);
    }
}

void up(int x){
    int k = x;
    while(k/2>=1&&heap[k]<heap[k/2]){
        swap_heap(k,k/2);
        k/=2;
    }
}

void insert(int v){
    heap[++cnt] = v;
    insert_k[++tt] = cnt;
    heap_k[cnt] = tt; //��¼��ǰ���ǵڼ��������
    up(cnt);
}

void update(int k,int val){
    // ȡ�õ�k�����������������±�
    k = insert_k[k];
    heap[k] = val;
    down(k);
    up(k);
}

void delete_k(int x){
    // ȡ�õ�x�����������������±�
    int k = insert_k[x];
    // ���߽���
    swap_heap(k,cnt);
    // ��ʱ��ɾ���ڵ����cntλ��,ɾ������ڵ�
    cnt--;
    down(k);
    up(k);
}

void delete_m(){
    swap_heap(1,cnt);
    cnt--;
    down(1);
    up(1);
}

int main(){
    int k,v,n;
    scanf("%d",&n);
    while(n--){
        getchar();
        char op1,op2;
        scanf("%c%c",&op1,&op2);
        if(op1=='I'){
            // ������ֵ
            scanf("%d",&v);
            insert(v);
        }else if(op1=='P'){
            // �����Сֵ
            printf("%d\n",heap[1]);
        }else if(op1=='C'){
            scanf("%d%d",&k,&v);
            update(k,v);
        }else if(op2=='M'){
            delete_m();
        }else if(op1=='D'){
            scanf("%d",&k);
            delete_k(k);
        }
    }
    return 0;
}
