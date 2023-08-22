#include<stdio.h>
typedef struct range{
	int begin,end;
}range; 
int n;
range all[100010];
// 用一个堆来维护各组内区间的最大右端点 
int heap[100010],cnt=0;

void quick_sort(int l,int r){
	range t = all[l];
	int ll = l,rr = r;
	while(ll<rr){
		while(ll<rr&&all[rr].begin>=t.begin) rr--;
		all[ll] = all[rr];
		while(ll<rr&&all[ll].begin<=t.begin) ll++;
		all[rr] = all[ll];
	}
	all[ll] = t;
	if(l<ll) quick_sort(l,ll-1);
	if(r>ll) quick_sort(ll+1,r);
}

void down(int x){
	int t = x;
	if(x*2<=cnt&&heap[x*2]<heap[t]) t = x*2;
	if(x*2+1<=cnt&&heap[x*2+1]<heap[t]) t = x*2+1;
	if(t!=x){
		heap[0] = heap[t];
		heap[t] = heap[x];
		heap[x] = heap[0];
		down(t);
	}
}

void up(int x){
	while(x/2>=1&&heap[x]<heap[x/2]){
		heap[0] = heap[x];
		heap[x] = heap[x/2];
		heap[x/2] = heap[0];
		x/=2;
	}
}

void push(int x){
	heap[++cnt] = x;
	up(cnt);
}

// 弹出堆顶区间右端点下标 
int pop(){
	int res = heap[1];
	heap[1] = heap[cnt--];
	down(1);
	return res;
}

// 要想让分组数最小,就应该让每个组内元素尽可能多 
int main(){
	int i,j,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		all[i].begin = a;
		all[i].end = b;
	}
	quick_sort(0,n-1);
	for(i=0;i<n;i++){
		// 如果当前区间左端点比最小右端点的组的右端点还小
		// 则这个区间必须开一个新组,并加入堆中 
		if(cnt==0||(cnt>=1&&all[i].begin<=heap[1])){
			push(all[i].end);
		}else{
			// 此时二者可以是一组
			pop();
			push(all[i].end);
		}
	}
	
	printf("%d\n",cnt);
	return 0;
}
