#include<iostream>
#include<string>
using namespace std;

// δ��AC  ��ʱ  ������4���� 
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
			//ȡ����Сֵ 
			minValue = 1000001;
			if(l==r){
				//��˵��Ҫ�������������l���ֵ
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
