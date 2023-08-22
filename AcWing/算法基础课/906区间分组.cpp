#include<stdio.h>
typedef struct range{
	int begin,end;
}range; 
int n;
range all[100010];
// ��һ������ά�����������������Ҷ˵� 
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

// �����Ѷ������Ҷ˵��±� 
int pop(){
	int res = heap[1];
	heap[1] = heap[cnt--];
	down(1);
	return res;
}

// Ҫ���÷�������С,��Ӧ����ÿ������Ԫ�ؾ����ܶ� 
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
		// �����ǰ������˵����С�Ҷ˵������Ҷ˵㻹С
		// �����������뿪һ������,��������� 
		if(cnt==0||(cnt>=1&&all[i].begin<=heap[1])){
			push(all[i].end);
		}else{
			// ��ʱ���߿�����һ��
			pop();
			push(all[i].end);
		}
	}
	
	printf("%d\n",cnt);
	return 0;
}
