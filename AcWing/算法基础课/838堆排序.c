#include<stdio.h>

int n,m;
int heap[100010];
int cnt;

void down(int cur){
    int t = cur;
    // 有左孩子且左孩子比当前点小
    if(cur*2<=cnt&&heap[cur*2]<heap[t]){
        t = 2*cur;
    }
    // 有右孩子且右孩子比当前点小
    if((cur*2+1)<=cnt&&heap[cur*2+1]<heap[t]){
        t = 2*cur+1;
    }
    // 最小的那个点不是根节点，说明根节点有问题，需要换位置
    if(t!=cur){
        heap[0] = heap[t];
        heap[t] = heap[cur];
        heap[cur] = heap[0];
        // 递归使该节点下沉
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

    // 建立初始堆
    for(i=n/2;i>=1;i--) down(i);

    while(m--){
        // 头节点为当前区域最小值
        printf("%d ",heap[1]);
        // 删除头节点，做法就是把当前区域最后一个值拿过来直接覆盖掉根节点
        heap[1] = heap[cnt--];
        // 重新down操作，保证堆结构合理
        down(1);
    }
    printf("\n");

    return 0;
}
