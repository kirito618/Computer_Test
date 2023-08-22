#include<stdio.h>
typedef struct range{
	int begin,end;
}range; 
int n;
range all[100010];

void quick_sort(int l,int r){
	range t = all[l];
	int ll = l,rr = r;
	while(ll<rr){
		while(ll<rr&&all[rr].end>=t.end) rr--;
		all[ll] = all[rr];
		while(ll<rr&&all[ll].end<=t.end) ll++;
		all[rr] = all[ll];
	}
	all[ll] = t;
	if(l<ll) quick_sort(l,ll-1);
	if(r>ll) quick_sort(ll+1,r);
}

int main(){
	int i,a,b,last,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		all[i].begin = a;
		all[i].end = b;
	}
	quick_sort(0,n-1);
	last = -2e9;
	for(i=0;i<n;i++){
		//printf("%d %d\n",all[i].begin,all[i].end);
		if(all[i].begin>last){
			last = all[i].end;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
