#include<stdio.h>
int M,head,back,idx;
int val[100010],ne[100010],la[100010] = {-1};

void init(){
    head = -1;
    back = -1;
    idx = 0;
}

void insert_to_head(int x){
    val[idx] = x;
    ne[idx] = head;
    la[idx] = -1;
    la[head] = idx;
    if(head==-1){
        back = idx;
    }
    head = idx;
    idx++;
}

void insert_to_back(int x){
    val[idx] = x;
    ne[idx] = -1;
    la[idx] = back;
    ne[back] = idx;
    if(back==-1){
        head = idx;
    }
    back = idx;
    idx++;
}

void delte_k(int k){
    int las = la[k-1];
    int nex = ne[k-1];
    if(k-1==head&&head==back){
        head = -1;
        back = -1;
    }else if(k-1==head){
        // �ǵ�һ��Ԫ��
        head = ne[head];
    }else if(k-1==back){
        // �����һ��Ԫ��
        back = la[back];
    }
    ne[las] = nex;
    la[nex] = las;
}

void insert_pre_k(int k,int x){
    int las = la[k-1];
    val[idx] = x;
    ne[idx] = k-1;
    la[idx] = las;
    if(las!=-1)
        ne[las] = idx;
    if(k-1==head){
        head = idx;
    }
    la[k-1] = idx;
    idx++;
}

void insert_after_k(int k,int x){
    int nex = ne[k-1];
    val[idx] = x;
    ne[idx] = nex;
    la[idx] = k-1;
    if(nex!=-1)
        la[nex] = idx;
    if(k-1==back){
        back = idx;
    }
    ne[k-1] = idx;
    idx++;
}

int main(){
    char op;
    int k,x;
    scanf("%d\n",&M);
    init();
    while(M--){
        scanf("%c",&op);
        if(op=='L'){
            // ��������x(��ͷ)
            scanf("%d",&x);
            insert_to_head(x);
        }else if(op=='R'){
            // ���Ҳ����x(��β)
            scanf("%d",&x);
            insert_to_back(x);
        }else if(op=='D'){
            // ɾ����k���������
            scanf("%d",&k);
            delte_k(k);
        }else{
            scanf("%c",&op);
            if(op=='L'){
                // �ڵ�k�����������߲���
                scanf("%d %d",&k,&x);
                insert_pre_k(k,x);
            }else{
                // �ڵ�k����������ұ߲���
                scanf("%d %d",&k,&x);
                insert_after_k(k,x);
            }
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
