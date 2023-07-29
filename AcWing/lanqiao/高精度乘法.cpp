#include<iostream>

using namespace std;

int result[10000];
string A,B;

int main(){
	int temp,jin;
	int x,y;
	cin>>A>>B;
	for(int i=A.length()-1;i>=0;i--){
		for(int j = B.length()-1;j>=0;j--){
			temp = (B[j]-'0')*(A[i]-'0');
			x = A.length()-1-i;
			y = B.length()-1-j;
			result[x+y]+=temp;
		}
	}
	
	x=0;
	y= A.length()+B.length()-2;
	
	jin = 0;
	while(x<=y){
		temp = (result[x]+jin)%10;
		jin = (result[x]+jin)/10;
		result[x] = temp;
		x++;
	}
	
	if(jin!=0){
		y++;
		result[y] = jin;
	}
	
	while(y>=0){
		cout<<result[y];
		y--;
	}
	
	return 0;
}
