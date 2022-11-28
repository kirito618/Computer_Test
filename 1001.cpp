#include<iostream>
#include<string>
using namespace std;

int main(){
	long a,b;
	int count = 0;
	bool flag = false;
	cin>>a>>b;
	long sum = a+b;
	if(sum==0){
		cout<<sum<<endl;
		return 0;
	}else if(sum<0){
		flag = true;
		sum = sum*(-1);
	}
	string data = "" + to_string(sum);
	string result = "";
	
	int length = data.length();
	int index = length-1;
	//格式化，每3个字符加个逗号。
	while(index>=0){
	    count++;
		result = data[index] + result;
		if(count%3==0&&index!=0){
			result = "," + result;
		}
		index--;
	}
	if(flag){
		result = "-" + result;
	}
	
	cout<<result<<endl;
	return 0;
}