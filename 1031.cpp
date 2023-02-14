#include<iostream>
#include<string>
using namespace std;

int main(){
	string origin,temp,result;
	int N,n1,n2,n3,i,j,k;
	cin>>origin;
	N = origin.length();
	i=0;
	j = N-1;
	k=0;
	result = "";
	while(1){
		// 用此过程来计算n1,n3
		n1++;
		n3++;
		n2 = N + 2 - n1 - n3;
		if(n1>=n2||n3>=n2){
			break;
		}
	}
	//此时若n1和n3是大于n2的，那么不符合要求，令n1-1,n2-1; 
	if(n1>n2||n3>n2){
		n1--;
		n3--;
		n2 = N+2-n1-n3;
	}
	
	// 处理除了最后一行以外的行 
	while(k<n1-1){
		result = result + origin[k];
		for(int i=0;i<n2-2;i++){
			result = result+" "; 
		}
		result = result + origin[N-1-k] + "\n";
		k++;
	}
	
	j=0;
	//处理最后一行
	while(j<n2){
		result = result + origin[k];
		j++;
		k++;
	}
	cout<<result<<endl;
	
	
	return 0;
} 
