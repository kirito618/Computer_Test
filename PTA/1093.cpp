#include<iostream>
#include<string>
using namespace std;

// ��AC 
long long T_nums[100010],P_nums[100010];

int main(){
	long long cnt = 0,last=0,i=0,j,temp;
	string input;
	cin>>input;
	
	// P[i]��¼i��λ�ü�ǰ���P�ĸ��� 
	P_nums[0] = input[0]=='P'?1:0;
	for(int x=1;x<input.length();x++){
		P_nums[x] = P_nums[x-1];
		if(input[x]=='P'){
			P_nums[x]++;
		}
	}
	
	// T[i]��¼i��λ�ü��Ժ��T�ĸ��� 
	for(int x=input.length()-1;x>=0;x--){
		T_nums[x] = T_nums[x+1];
		if(input[x]=='T'){
			T_nums[x]++;
		}
	}
	
	while(i<input.length()){
		if(input[i]=='A'){
			cnt += T_nums[i]*P_nums[i];
		}
		i++;
	}
	cnt = cnt%1000000007;
	cout<<cnt<<endl;
	
	return 0;
}
