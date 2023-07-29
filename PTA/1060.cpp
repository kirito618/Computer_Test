#include<iostream>
#include<string>
using namespace std;
int N;
// 记录要乘以多少个10才能恢复原样 
int count_right[2];
string a,b,subA,subB;

string getSub(string x,int order){
	string subStr = "";
	int i = 0,j,len;
	while(i<x.length()){
		if(x[i]=='.') break;
		i++;
	}
	// 此时i要么在串尾 要么在 . 符号处
	if(i==x.length()){
		for(j=0;j<x.length();j++){
			if(x[j]!='0') break;
		}
		if(j==x.length()){
			// 全是0
			count_right[order] = 0;
		}else{
			count_right[order] = x.length() - j;
		}
		// 说明没有点  那么直接按要求去截取串
		subStr = x.substr(j,N);
	}else{
		// 有小数点，划分出小数点前和小数点后 
		string front = x.substr(0,i);
		string after = x.substr(i+1);
		int temp_len;
		for(j=0;j<front.length();j++){
			if(front[j]!='0') break;
		}
		
		if(j!=front.length()){
			// 说明存在有效数字在小数点前
			temp_len = front.length()-j;
			subStr += front.substr(j,N); 
			count_right[order] = temp_len;
		}else{
			count_right[order]=0;
		}
		
		if(subStr.length()<N&&subStr.length()>0){
			// 说明前面存在有效数字
			// 并且只靠小数点前的有效部分还不够
			temp_len = N - subStr.length();
			subStr += after.substr(0,temp_len); 
		}else if(subStr.length()==0){
			// 说明前面压根就没有有效数字 全是0
			for(j=0;j<after.length();j++){
				// 找到第一个有效数字 
				if(after[j]!='0') break;
			}
			if(j==after.length()){
				//说明小数部分也没有有效数字 说明这个数就是0 
				count_right[order] = 0;
				subStr = "";
			}else{
				// 存在有效数字，且j位于第一个有效数字
				// j的值就代表前面有几个0
				count_right[order] = -1*j;
				temp_len = after.length() - j + 1;
				temp_len = temp_len<N?temp_len:N;
				subStr += after.substr(j,temp_len); 
			}
		}

	}
	// 补0 
	if(subStr.length()<N){
		len = subStr.length();
		// 补0 
		for(j=0;j<N-len;j++){
			subStr+='0';
		}
	}
	
	return subStr;
}

int main(){
	cin>>N>>a>>b;
	string tempA = getSub(a,0);
	string tempB = getSub(b,1);
	if(tempA==tempB&&count_right[0]==count_right[1]){
		cout<<"YES"; 
		cout<<" 0."<<tempA<<"*10^"<<count_right[0]<<endl;

	}else{
		cout<<"NO";
		cout<<" 0."<<tempA<<"*10^"<<count_right[0];
		cout<<" 0."<<tempB<<"*10^"<<count_right[1]<<endl;
	}

	return 0;
} 
