#include<iostream>
#include<string>
using namespace std;
int N;
// ��¼Ҫ���Զ��ٸ�10���ָܻ�ԭ�� 
int count_right[2];
string a,b,subA,subB;

string getSub(string x,int order){
	string subStr = "";
	int i = 0,j,len;
	while(i<x.length()){
		if(x[i]=='.') break;
		i++;
	}
	// ��ʱiҪô�ڴ�β Ҫô�� . ���Ŵ�
	if(i==x.length()){
		for(j=0;j<x.length();j++){
			if(x[j]!='0') break;
		}
		if(j==x.length()){
			// ȫ��0
			count_right[order] = 0;
		}else{
			count_right[order] = x.length() - j;
		}
		// ˵��û�е�  ��ôֱ�Ӱ�Ҫ��ȥ��ȡ��
		subStr = x.substr(j,N);
	}else{
		// ��С���㣬���ֳ�С����ǰ��С����� 
		string front = x.substr(0,i);
		string after = x.substr(i+1);
		int temp_len;
		for(j=0;j<front.length();j++){
			if(front[j]!='0') break;
		}
		
		if(j!=front.length()){
			// ˵��������Ч������С����ǰ
			temp_len = front.length()-j;
			subStr += front.substr(j,N); 
			count_right[order] = temp_len;
		}else{
			count_right[order]=0;
		}
		
		if(subStr.length()<N&&subStr.length()>0){
			// ˵��ǰ�������Ч����
			// ����ֻ��С����ǰ����Ч���ֻ�����
			temp_len = N - subStr.length();
			subStr += after.substr(0,temp_len); 
		}else if(subStr.length()==0){
			// ˵��ǰ��ѹ����û����Ч���� ȫ��0
			for(j=0;j<after.length();j++){
				// �ҵ���һ����Ч���� 
				if(after[j]!='0') break;
			}
			if(j==after.length()){
				//˵��С������Ҳû����Ч���� ˵�����������0 
				count_right[order] = 0;
				subStr = "";
			}else{
				// ������Ч���֣���jλ�ڵ�һ����Ч����
				// j��ֵ�ʹ���ǰ���м���0
				count_right[order] = -1*j;
				temp_len = after.length() - j + 1;
				temp_len = temp_len<N?temp_len:N;
				subStr += after.substr(j,temp_len); 
			}
		}

	}
	// ��0 
	if(subStr.length()<N){
		len = subStr.length();
		// ��0 
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
