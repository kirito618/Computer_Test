#include<iostream>
#include<string>
using namespace std;

int top = 0;// top==0��ʶջ�գ�topָ����һ������λ�� 
int M;
int st[100010];
 
int main(){
	string op;
	int t;
	cin>>M;
	while(M--){
		cin>>op;
		if(op.length()==4){
			// push
			cin>>t;
			st[top++] = t;
		}else if(op.length()==3){
			// pop
			top--;
		}else{
			if(op[0]=='q'){
				// query
				cout<<st[top-1]<<endl;
			}else{
				//empty
				if(top==0) puts("YES");
				else puts("NO");
			}
		}
	}
	
	return 0;
} 
