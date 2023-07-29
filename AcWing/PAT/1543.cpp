#include<iostream>
#include<string>
#include<set>
using namespace std;

int m;
int st[100010];
int top = 0,bottom=0;
multiset<int> db;

int main(){
	int num;
	string op;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>op;
		if(op.length()==4){
			// Push ²Ù×÷
			cin>>num;
			st[top++] = num;
			db.insert(num);
		}else if(op.length() == 3){
			if(top==bottom){
				cout<<"Invalid"<<endl;
			}else{
				num = st[--top];
				cout<<num<<endl;
				db.erase(db.find(num));
			}
		}else{
			int j = 1;
			if(top==bottom){
				cout<<"Invalid"<<endl;
				continue;
			}
			num = top%2==0?(top/2):((top+1)/2);
			for(multiset<int>::iterator x=db.begin();x!=db.end();x++,j++){
				if(j==num){
				    cout<<*x<<endl;
					break;
				}
			}
		}
	}
	
	return 0;
} 
