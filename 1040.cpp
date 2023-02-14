#include<iostream>
#include<string>
using namespace std;

int max_len = 0; 
int len;
string origin;
int main(){
	int j,k;
	getline(cin,origin);
	if(origin.length()==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<origin.length();i++){
		len = 0;
		j=i;
		k=origin.length()-1;
		while(j<=k){
			if(origin[j]!=origin[k]){
				k--;
				j=i;
				len = 0;
			}else{
				if(j==k){
					len++;
				}else{
					len+=2;
				}
				k--;
				j++;
			}
		}

		if(len!=0){
			//说明是个回文串，记录比对一下长度 
			if(len>max_len){
				max_len = len;
			}
		}
	}
	cout<<max_len<<endl;
	return 0;
}
