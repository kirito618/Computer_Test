#include<bits/stdc++.h>

using namespace std;

map<string,set<int>> stu_course;
int N,K;

// ½«×Ö·û´®×ª³Éint´æ´¢ 

int main(){
	int c,a,tempKey;
	string temp;
	cin>>N>>K;
	for(int i=0;i<K;i++){
		cin>>c>>a;
		for(int j=0;j<a;j++){
			cin>>temp;
			stu_course[temp].insert(c);	
		}
	}
	
	for(int i=0;i<N;i++){
		cin>>temp;
		cout<<temp;
		if(stu_course.count(temp)==0){
			cout<<" 0"<<endl;
		}else{
			cout<<" "<<stu_course[temp].size();
			for(int x:stu_course[temp]){
				cout<<" "<<x;
			}
			cout<<endl;
		}
	}
	return 0;
}
