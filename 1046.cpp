#include<iostream>
using namespace std;

int N,M,dis,all_dis,temp;
int distances[100000];
int sum_to_one[100001];
int main(){
	int a,b,reverse,min_dis;
	cin>>N;
	// ��¼�ܾ��� 
	all_dis = 0;
	for(int i=0;i<N;i++){
		cin>>distances[i];
		all_dis += distances[i];
	}
	
	dis = 0;
	// N�ξ���,����N+1����,��¼ÿ���㵽��һ����ľ��� 
	for(int i=0;i<N+1;i++){
		sum_to_one[i] += dis;
		if(i==N) continue;
		dis += distances[i];
	}
	
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		if(a>b){
			temp = b;
			b = a;
			a = temp;
		}
		// ������������ 
		dis = sum_to_one[b-1] - sum_to_one[a-1];
		reverse = all_dis - dis;
		min_dis = dis<reverse?dis:reverse;
		cout<<min_dis<<endl;
	}
	
	return 0;
}
