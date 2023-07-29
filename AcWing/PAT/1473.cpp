#include<iostream>
#include<string>

using namespace std;

int main(){
	int a,b;
	int count = 0;
	string result;
	cin>>a>>b;
	result = to_string(a+b);
	for(int i=0;i<result.length();i++){
		cout<<result[i];
		if(result[i]!='-'&&i!=result.length()-1&&(result.length()-1-i)%3==0) cout<<",";
	}
	
	return 0;
}
