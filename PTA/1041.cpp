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
			//�ҵ��˵�һ����һ�޶����������������ѭ��
			cout<<bets[j]<<endl;
			break;
		}
	}
	if(j==N) cout<<"None"<<endl;
	return 0;
} 
