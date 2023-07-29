#include<iostream>
using namespace std;

int N,cur,res=0;

int main(){
	int req;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>req;
		if(req<cur){
			res+=(cur-req)*4;
		}else{
			res+=(req-cur)*6;
		}
		cur = req;
		res+=5;
	}
	cout<<res<<endl;
	return 0;
}
