#include<stdio.h>
int arr[100010];
int k;

int main(){
	int n,q,i,mid,l,r;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	while(q--){
		scanf("%d",&k);
		l = 0;
		r = n-1;
		while(l<r){
			// >>1表示右移1位,实际上就是除以2 
			mid = l+r>>1;
			if(arr[mid]>=k) r = mid;
			else l = mid+1;
		}
		if(arr[l]!=k){
			// 说明数组里根本就没有
			puts("-1 -1"); 
		}else{
			printf("%d ",l);
			l = 0,r = n-1;
			while(l<r){
				mid = l+r+1>>1;
				if(arr[mid]<=k) l = mid;
				else r = mid-1;
			}
			printf("%d\n",r);
		}
	}
	
	return 0;
} 
