#include<iostream>
#include<string>
using namespace std;

// 未能AC  超时  仅过了4个点 
int arr[200000];
int main(){
	int n,m,l,r,d;
	int minValue;
	string code;
	char x;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		scanf("%d %d%c",&l,&r,&x);
		if(x==' '){
			cin>>d;
			if(l==r){
				arr[l]+=d;
			}else{
				arr[l] += d;
				arr[r] += d;
				l = (l+1)%n;
				while(l!=r){
					arr[l] += d;
					l = (l+1)%n;
				}
			}
			
		}else{
			//取出最小值 
			minValue = 1000001;
			if(l==r){
				//那说明要操作的区间就是l这个值
				minValue = arr[l]; 
			}else{
				//l!=r
				minValue = arr[l]<arr[r]?arr[l]:arr[r];
				while(l!=r){
					if(arr[l]<minValue){
						minValue = arr[l];
					}
					l = (l+1)%n;
				}
			}
			printf("%d\n",minValue);
		}
	}
	
	return 0;
}
