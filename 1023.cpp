#include<iostream>
#include<string>
using namespace std;

// digit[i] ��������i�ĸ��� (1-9)
int digits[10],digit;
int jin;
string originNum;
string result,result2;
bool flag = false;
bool compare = false;
int x;

int main(){
	cin>>originNum;
	result = originNum+"";
	result2 = result+"";
	for(int i=0;i<10;i++) digits[i] = 0;
	// ��¼ÿһλ�м���
	for(int i=0;i<originNum.length();i++){
		digits[originNum[i] - '0']++;
	}
	jin = 0;
	for(int i=originNum.length()-1;i>=0;i--){
		digit = originNum[i] - '0';
		digit = digit*2 + jin;
		jin = digit/10;
		digit = digit%10;
		digits[digit]--;
		result[i] = (char)('0'+digit);
	}
	
	if(jin==1){
		//���н�λ
		result = "1"+result;
		digits[result[0]-'0']--;
	}
	
	for(int i=0;i<10;i++){
		if(digits[i]!=0){
			//������û���꣡
			flag = true;
			break;
		}
	}
	
	x=0;
	while(x<originNum.length()){
		if(result[x]!=originNum[x]){
			break;
		}
		x++;
	}
	if(x==originNum.length()){
		//������һģһ��
		compare = true; 
	}
	
	
	if(flag||compare){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}

	cout<<result<<endl;
	return 0;
}
