#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long origin,temp,N,base,yu;
vector<long long> digits;

int main(){
	string num;
	bool flag = true;
	int i,j,k;
	long long resultNum=0;
	cin>>origin>>base;
	temp = origin;
	// 进制转换
	while(temp>0){
		yu = temp%base;
		temp = temp/base;
		num = to_string(yu) + num;
		digits.push_back(yu);
	}
	i=0;
	k = digits.size()-1;
	while(i<k){
		if(digits[i]!=digits[k]){
			flag = false;
			break;
		}
		i++;
		k--;
	}

	if(!flag){
		// 不是回文串 
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl; 
	}
	
	i=digits.size()-1;
	cout<<digits[i];
	i--;
	while(i>=0){
		cout<<" "<<digits[i];
		i--;
	}
	cout<<endl;
	return 0;
}
