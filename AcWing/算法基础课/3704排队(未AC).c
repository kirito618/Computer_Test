#include<stdio.h>
int N,M,hN=0;
int ru[510];
int he[510],val[510],ne[510],cnt=0;
int heap[510];

// ͷ�巨
void add(int a,int b){
    val[cnt] = b;
    ne[cnt] = he[a];
    he[a] = cnt++;
}

void down(int i){
    int k = i;
    if(2*i<=hN&&heap[2*i]<heap[k]) k = 2*i;
    if(2*i+1<=hN&&heap[2*i+1]<heap[k]) k = 2*i+1;
    if(k!=i){
        heap[0] = heap[k];
        heap[k] = heap[i];
        heap[i] = heap[0];
        down(k);
    }
}

void up(int i){
    while(i/2>0&&heap[i]<heap[i/2]){
        heap[0] = heap[i/2];
        heap[i/2] = heap[i];
        heap[i] = heap[0];
        i /= 2;
    }
}

void insert_to_heap(int v){
    heap[++hN] = v;
    up(hN);
}

int delete_min_heap(){
    int t = heap[1];
    heap[1] = heap[hN--];
    down(1);
    return t;
}

void top_sort(){
    int i,j,h;
    for(i=1;i<=N;i++){
        if(ru[i]==0){
            insert_to_heap(i);
        }
    }
    while(hN>0){
        h = delete_min_heap();
        printf("%d ",h);
        for(i=he[h];i!=-1;i=ne[i]){
            ru[val[i]]--;
            if(ru[val[i]]==0){
                insert_to_heap(val[i]);
            }
        }
    }
}

int main(){
    int i,j,a,b,h;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++) he[i]=-1;
    for(i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        add(a,b);
        ru[b]++;
    }
    top_sort();
    return 0;
}
