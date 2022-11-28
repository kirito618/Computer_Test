#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
int main(){
	//A是系数数组(从大到小)
	double A[1001];
	//先全置为0 
	for(int i=0;i<=1000;i++)A[i]=0;
	//用来统计非0项的个数 
	int count = 0;
	for(int l=0;l<2;l++){
	   //K: 非零项的个数 N: 指数，M：系数 
	   int K,N;
	   double M;
	   
	   cin>>K;
	   for(int i=0;i<K;i++){
		   cin>>N>>M;
		   A[N] += M;
	   }
	}
	
	for(int i=0;i<1001;i++){
		if(A[i]!=0)
		   count++;
	}
	if(count==0){
		cout<<0<<endl;
		return 0;
	}
	
	cout<<count;
	for(int i=1000;i>=0;i--){
		if(A[i]!=0){
			cout<<" "<<i<<" ";
			printf("%.1f",A[i]);
		}
	}
	cout<<endl;
	
	return 0;
} 