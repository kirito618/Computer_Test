#include<iostream>
using namespace std;

long int S[3][2000000];
int N[2];

int main(){
	long int temp;
	int len,index=0,x,y;
	
	for(int i=0;i<200001;i++){
		S[0][i] = 0;
		S[1][i] = 0;
		S[2][i] = 0;
	}
	for(int i=0;i<2;i++){
		cin>>x;
		N[i] = x;
		for(int j=0;j<x;j++){
			cin>>temp;
			S[i][j] = temp;
		}
	}
	x=0;
	y=0;
	index=0;
	len = N[0]+N[1];
	while((index<len)&&(x<N[0])&&(y<N[1])){
		if(S[0][x]<=S[1][y]){
			S[2][index] = S[0][x];
			x++;
		}else{
			S[2][index] = S[1][y];
			y++;
		}
		index++;
	}
	
	//处理没有加上的值
	if(x==N[0]&&index<len){
		while(y<N[1]&&index<len){
			if(y<N[1]){
				S[2][index] = S[1][y];
				y++;
				index++;
			}
		}
	}else if(y==N[1]&&index<len){
		while(x<N[0]&&index<len){
			if(x<N[0]){
				S[2][index] = S[0][x];
				x++;
				index++;
			}
		}
	}
	index = (index-1)/2;
	cout<<S[2][index]<<endl;
	
	return 0;
}

