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
		// �ô˹���������n1,n3
		n1++;
		n3++;
		n2 = N + 2 - n1 - n3;
		if(n1>=n2||n3>=n2){
			break;
		}
	}
	//��ʱ��n1��n3�Ǵ���n2�ģ���ô������Ҫ����n1-1,n2-1; 
	if(n1>n2||n3>n2){
		n1--;
		n3--;
		n2 = N+2-n1-n3;
	}
	
	// ����������һ��������� 
	while(k<n1-1){
		result = result + origin[k];
		for(int i=0;i<n2-2;i++){
			result = result+" "; 
		}
		result = result + origin[N-1-k] + "\n";
		k++;
	}
	
	j=0;
	//�������һ��
	while(j<n2){
		result = result + origin[k];
		j++;
		k++;
	}
	cout<<result<<endl;
	
	
	return 0;
} 
