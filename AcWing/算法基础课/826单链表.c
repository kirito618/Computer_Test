#include<stdio.h>

// val[i] ��ŵ�i������Ľڵ㣬ne[i] ��ŵ�i������ڵ����һ���ڵ�Ĳ���λ��(�������е�λ��)
int val[100010],ne[100010] = {-1};
// headָ����ף�idxָ����һ���ɲ�������鵥Ԫ(�Ͷ��е�ttͬ��)
int head,idx;

void init(){
    // ����Ϊ��
    head = -1;
    idx = 0;
}

// ������ͷ������һ���ڵ�
void insert_to_head(int x){
    val[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// �ڵ�k������Ľڵ�������һ���ڵ�
void insert_after_k(int x,int k){
    // ��k�����������������±���k-1
    // ȡ��������һ���ڵ�λ��
    int nex = ne[k-1];
    val[idx] = x;
    ne[idx] = nex;
    ne[k-1] = idx;
    idx++;
}

// ɾ����k����������������
void delete_after_k(int k){
    if(k==0){
        // ɾ��ͷ�ڵ�
        head = ne[head];
        return ;
    }
    int nex = ne[k-1];
    ne[k-1] = ne[nex];
}

int main(){
    int M;
    int x,k;
    char o;
    init();
    scanf("%d\n",&M);
    while(M--){
        scanf("%c",&o);
        if(o=='H'){
            scanf("%d",&x);
            insert_to_head(x);
        }else if(o=='D'){
            scanf("%d",&k);
            delete_after_k(k);
        }else{
            scanf("%d %d",&k,&x);
            insert_after_k(x,k);
        }
        getchar();
    }

    int i = head;
    while(i!=-1){
        printf("%d ",val[i]);
        i = ne[i];
    }
    printf("\n");
    return 0;
}
