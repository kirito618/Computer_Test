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
			//˵����������x���� ��ô��Ҫ�Ķ�i��ֵ
			i = j-1; 
			if(temp>2){
				//˵��������x�Ѿ�������2�� ��ô�����Ĳ��ֶ���Ҫɾ�� 
				del += (temp-2);
			}
		}
	}
	cout<<del<<endl;
	return 0;
} 
