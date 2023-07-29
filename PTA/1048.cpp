#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}

int N,M,sum;
int coins[100000];
bool handle[501];
int main(){
	int k = 0;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>coins[i];
		handle[coins[i]] = false;
	}
	sort(coins,coins+N,cmp);
	while(coins[k]+coins[N-1]<M&&k<N) k++;
	for(int i=0;i<N-1;i++){
		// 如果重复的一个数已经处理过一次 那么跳过这次循环
		// 要不然太多重复的必定超时 
		if(handle[coins[i]]) continue;
		for(int j=N-1;j>i;j--){
			sum = coins[i]+coins[j];
			if(sum==M){
				cout<<coins[i]<<" "<<coins[j]<<endl;
				return 0;
			}else if(sum<M){
				break;
			}
		}
		handle[coins[i]] = true;
	}
	cout<<"No Solution"<<endl;
	return 0;
}
