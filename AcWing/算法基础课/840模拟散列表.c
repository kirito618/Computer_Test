#include<stdio.h>
#include<stdlib.h>

int MAX = 100010;
int h[100010],val[100010],ne[100010],idx=0;

// 拉链法处理哈希冲突,头插法
void insert_link(int x){
    // 直接取余得到存放位置
    int i = (x%MAX+MAX)%MAX;
    val[idx] = x;
    ne[idx] = h[i];
    h[i] = idx++;
}

// 拉链法查找是否存在元素
int find_link(int x){
    // 直接取余得到存放位置
    int i = (x%MAX+MAX)%MAX;
    // 取得拉链头节点
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
