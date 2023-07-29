#include<stdio.h>

// val[i] 存放第i个插入的节点，ne[i] 存放第i个插入节点的下一个节点的插入位序(在数组中的位置)
int val[100010],ne[100010] = {-1};
// head指向队首，idx指向下一个可插入的数组单元(和队列的tt同理)
int head,idx;

void init(){
    // 链表为空
    head = -1;
    idx = 0;
}

// 在链表头部插入一个节点
void insert_to_head(int x){
    val[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 在第k个插入的节点后面插入一个节点
void insert_after_k(int x,int k){
    // 第k个插入的数在数组的下标是k-1
    // 取得它的下一个节点位序
    int nex = ne[k-1];
    val[idx] = x;
    ne[idx] = nex;
    ne[k-1] = idx;
    idx++;
}

// 删除第k个插入的数后面的数
void delete_after_k(int k){
    if(k==0){
        // 删除头节点
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
