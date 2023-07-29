#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 存放被修改了的字符串的下标 
vector<int> modified;
int N;
int len,i,count;
bool if_modified;
string ids[1000],password[1000];

void modified_method(string pass,int index){
	if_modified = false;
	i=0;
	len = pass.length();
	while(i<len){
		if(pass[i]=='1'){
			pass[i] = '@';
			if_modified = true;
		}else if(pass[i]=='0'){
			pass[i] = '%';
			if_modified = true;
		}else if(pass[i]=='l'){
			pass[i] = 'L';
			if_modified = true;
		}else if(pass[i]=='O'){
			pass[i] = 'o';
			if_modified = true;
		}
		i++;
	}
	if(if_modified){
		password[index] = pass;
	}
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>ids[i]>>password[i];
		getchar();
	}
	
	//count记录有多少个密码被修改过了 
	count = 0;
	for(int i=0;i<N;i++){
		modified_method(password[i],i);
		if(if_modified){
			//修改过了
			modified.push_back(i);
			count++;
		}
	}
	if(count!=0){
		cout<<count<<endl;
		for(int ind:modified){
			cout<<ids[ind]<<" "<<password[ind]<<endl;
		}
	}else{
		//没有账号被修改 
		if(N==1){
			cout<<"There is 1 account and no account is modified"<<endl;
		}else{
			cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
		}
	}
	return 0;
}
