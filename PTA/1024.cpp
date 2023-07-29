#include<iostream>
#include<string>
using namespace std;

// 逻辑是对的，就是它输入的内容太大，接不下 
// 通过Java版的成功AC了！ 
long long N,K;

long long reverse(long long N){
	string temp = to_string(N);
	long long result = 0;
	for(int i=temp.length()-1;i>=0;i--){
		result = result * 10 + (temp[i]-'0');
	}
	return result;
}

bool ifPalindromic(long long num){
	string temp = to_string(num);
	int i=0,j=temp.length()-1;
	while(i<j){
		if(temp[i]!=temp[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main(){
	long long sum,step = 0;
	cin>>N>>K;
	sum = N;
	
	if(ifPalindromic(N)||to_string(N).length()==1){
		cout<<sum<<"\n"<<step<<endl;
		return 0;
	}
	while(K>0){
		step++;
		sum = sum + reverse(sum);
		if(ifPalindromic(sum)){
			break;
		}
		K--;
	}
	
	cout<<sum<<"\n"<<step<<endl;
	return 0;
}
