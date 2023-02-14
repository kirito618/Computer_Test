#include<iostream>
using namespace std;

int N,V,take,off;
int weight[1000],value[1000];

int dp(int cur,int wei){
	cout<<weight[cur]<<endl;
	if(weight==0 || cur==N){
		return 0;
	}
	
	take = 0;
	if(wei - weight[cur]>=0){
		take = value[cur] + dp(cur+1,wei-weight[cur]);
	}
	off = dp(cur+1,wei);
	return take>=off?take:off;
}

int main(){
	cin>>N>>V;
	for(int i=0;i<N;i++){
		cin>>weight[i]>>value[i];
	}
	
	int result = dp(0,V);
	cout<<result<<endl;
	return 0;
}
