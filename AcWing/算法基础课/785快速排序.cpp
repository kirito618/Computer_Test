#include<stdio.h>
int n,arr[100010];

void quick_sort(int l,int r){
	if(l>=r) return ;
	int i = l,j = r,t;
	int x = arr[l];
	while(i<j){
		while(i<j&&arr[j]>=x) j--;
		while(i<j&&arr[i]<=x) i++;
		if(i<j){
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	// l即为中心点应该摆放的位置,让它与基准值进行交换
	arr[l] = arr[i];
	arr[i] = x;
	quick_sort(l,i-1);
	quick_sort(i+1,r); 
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	quick_sort(0,n-1);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
	return 0;
} 
