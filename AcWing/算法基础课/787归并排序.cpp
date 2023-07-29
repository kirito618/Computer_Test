#include<iostream>
using namespace std;

int n;
int arr[100010],t1[100010]; 

// 将下标[l1,r1]和[l2,r2]的区间进行合并 
void merge(int l1,int r1,int l2,int r2){
	// 总区间长度 
	int t = 0;
	int i = l1,j = l2;
	while(i<=r1&&j<=r2){
		if(arr[i]<=arr[j]){
			t1[t++] = arr[i];
			i++;
		}else{
			t1[t++] = arr[j];
			j++;
		}
	}
	while(i<=r1){
		t1[t++] = arr[i];
		i++;
	}
	while(j<=r1){
		t1[t++] = arr[j];
		j++;
	}
	for(int i=l1;i<l1+t;i++){
		arr[i] = t1[i-l1];
	}
}

void merge_sort(int l,int r){
	if(l>=r) return ;
	int mid = (l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	merge(l,mid,mid+1,r);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	merge_sort(0,n-1);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	return 0;
} 
