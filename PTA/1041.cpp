#include<iostream>
using namespace std;

int N;
int num_count[10001];
int bets[100000];

int main(){
	int j;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>bets[i];
		num_count[bets[i]]++;
	}
	for(j=0;j<N;j++){
		if(num_count[bets[j]]==1){
			//找到了第一个独一无二的数，输出并结束循环
			cout<<bets[j]<<endl;
			break;
		}
	}
	if(j==N) cout<<"None"<<endl;
	return 0;
} 
