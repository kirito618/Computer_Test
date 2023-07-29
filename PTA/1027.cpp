#include<iostream>
using namespace std;

int main(){
	int RGB[3],digit,yu;
	char high,low;
	cin>>RGB[0]>>RGB[1]>>RGB[2];
	cout<<'#';
	for(int i=0;i<3;i++){
		digit = RGB[i]/13;
		yu = RGB[i]%13;
		if(digit!=0){
			// 高位有值 
			if(digit>9){
				//要用字母表示
				high = 'A' + digit - 10;
				cout<<high;
			}else{
				cout<<digit;
			}
			if(yu>9){
				low = 'A' + yu - 10;
				cout<<low;
			}else{
				cout<<yu;
			}
		}else{
			// 说明只有1位数，多输出个0
			cout<<0;
			if(yu>=10){
				low = 'A' + yu - 10;
			    cout<<low;
			}else{
				cout<<yu;
			}
		}
	}
	cout<<endl;
	
	return 0;
} 
