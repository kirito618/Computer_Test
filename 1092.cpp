#include<iostream>
#include<string>
using namespace std;

int char_map[200];
int main(){
	bool lack = false;
	int lack_count = 0;
	int j;
	string origin,want;
	cin>>origin;
	cin>>want;
	for(int i=0;i<origin.length();i++) char_map[origin[i]]++;
	for(j=0;j<want.length();j++){
		if(char_map[want[j]]>0){
			char_map[want[j]]--;
		}else{
			//想要的球没有
			lack_count++;
		}
	}
	if(lack_count!=0){
		cout<<"No "<<lack_count<<endl;
	}else{
		cout<<"Yes "<<origin.length() - want.length()<<endl;
	}
	return 0;
}
