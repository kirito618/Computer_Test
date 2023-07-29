#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,temp;
	int i,j;
	int del = 0; 
	string str;
	cin>>n>>str;
	for(i=0;i<n;i++){
		j = i;
		temp = 0;
		while(str[j]=='x'){
			j++;
			temp++;
		}
		if(temp>0){
			//说明有连续的x出现 那么需要改动i的值
			i = j-1; 
			if(temp>2){
				//说明连续的x已经超过了2个 那么超出的部分都需要删掉 
				del += (temp-2);
			}
		}
	}
	cout<<del<<endl;
	return 0;
} 
