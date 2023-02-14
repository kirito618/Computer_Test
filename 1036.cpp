#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N,difference;
string name,sex,id,grade;
int maxFemale=-1,minMale=-1;
int maxValue = -1,minValue = 101,tempValue;
bool flag_F = false,flag_M = false;
vector<string> database[10000];

int str_int(string temp){
	int result = 0;
	for(int i=0;i<temp.length();i++){
		result = result*10 + (temp[i] - '0');
	}
	return result;
}

int main(){
	cin>>N;
	// 输入数据 
	for(int i=0;i<N;i++){
		cin>>name>>sex>>id>>grade;
		database[i].push_back(name);
		database[i].push_back(sex);
		database[i].push_back(id);
		database[i].push_back(grade);
	}
	for(int i=0;i<N;i++){
		if(database[i][1] == "F") flag_F = true;
		if(database[i][1] == "M") flag_M = true;
	}
	
	if(flag_F) {
		for(int i=0;i<N;i++){
			tempValue = str_int(database[i][3]);
			if(database[i][1]=="F"){
				// 是女学生 
				if(tempValue>maxValue){
			    	maxValue = tempValue;
					maxFemale = i;
				}
			}
		}
		cout<<database[maxFemale][0]<<" "<<database[maxFemale][2]<<endl;
	}else{
		cout<<"Absent\n";
	}
	if(flag_M) {
		for(int i=0;i<N;i++){
			tempValue = str_int(database[i][3]);
			if(database[i][1]=="M"){
			// 是男学生
				if(tempValue<minValue){
					minValue = tempValue;
					minMale = i;
				}
			}
		}
		cout<<database[minMale][0]<<" "<<database[minMale][2]<<endl;
	}else{
		cout<<"Absent\n";
	}

	
	if(flag_F&&flag_M){
		difference = maxValue - minValue;
		if(difference<0) difference*=-1;
		cout<<difference<<endl;
	}else{
		cout<<"NA"<<endl;
	}
	return 0;
} 
