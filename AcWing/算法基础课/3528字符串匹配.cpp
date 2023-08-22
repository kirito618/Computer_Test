#include<iostream>
#include<string.h>
using namespace std;
int n;
string s[1010],p;

string toLower(string input){
	string res = "";
	for(int i=0;i<input.size();i++){
		res += tolower(input[i]);
	}
	return res;
}

bool match(string input){
	int i,j;
	string temp;
	for(i=0,j=0;i<input.size()||j<p.size();i++){
		if(i==input.size()||j==p.size()) return false;
		if(p[j]!='['){
			if(input[i]!=p[j]) return false;
			j++;
		}else{
			temp = "";
			j++;
			while(p[j]!=']') temp += p[j++];
			j++;
			if(temp.find(input[i])==-1) return false;
		}
	}
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	cin>>p;
	p = toLower(p);
	for(int i=0;i<n;i++){
		if(match(toLower(s[i]))) cout<<i+1<<" "<<s[i]<<endl;
	}
} 
