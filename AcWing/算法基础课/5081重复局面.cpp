#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> cnt;
int n,P=131;
string g[110];

int main(){
	string t,tt;
	cin>>n;
	for(int i=0;i<n;i++){
		t = "";
		for(int j=0;j<8;j++){
			cin>>tt;
			t += tt;
		}
		cnt[t]++;
		cout<<cnt[t]<<endl;
	}
	return 0;
}
