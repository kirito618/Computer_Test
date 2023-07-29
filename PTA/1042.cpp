#include<iostream>
#include<string>
using namespace std;

int K;
string cards[54];
string head[5];
string result[54]; 
int order[54];

void sort_method(){
	
}

int main(){
	int index = 0;
	int temp_order;
	string temp_str;
	cin>>K;
	for(int i=0;i<54;i++){
		cin>>order[i];
	}
	head[0] = "S";
	head[1] = "H";
	head[2] = "C";
	head[3] = "D";
	head[4] = "J";
	
	for(int i=0;i<5;i++){
		if(head[i]=="J"){
			cards[index] = head[i]+to_string(1);
			index++;
			cards[index] = head[i]+to_string(2);
			index++;
		}else{
			for(int j=1;j<=13;j++){
				cards[index] = head[i]+to_string(j);
				index++;
			}
		}
	}
	
	for(int i=0;i<K;i++){
		for(int j=0;j<54;j++){
			//把i位置的卡片移动到j位置
			result[order[j]-1] = cards[j];
		}
		for(int j=0;j<54;j++){
			cards[j] = result[j];
		}
		
	}
	cout<<result[0];
	for(int x=1;x<54;x++) cout<<" "<<result[x];
	cout<<endl;
	return 0;
} 
