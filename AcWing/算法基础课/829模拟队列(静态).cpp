#include<iostream>
#include<string>
using namespace std;

int hh = 0,tt=0; //hhΪ��ͷ��ttΪ��һ������λ�� 
int M;
int q[100010];
 
int main(){
	string op;
	int t;
	cin>>M;
	while(M--){
		cin>>op;
		if(op.length()==4){
			// push
			cin>>t;
			q[tt++] = t;
		}else if(op.length()==3){
			// pop
			hh++;
		}else{
			if(op[0]=='q'){
				// query
				cout<<q[hh]<<endl;
			}else{
				//empty
				if(hh==tt) puts("YES");
				else puts("NO");
			}
		}
	}
	
	return 0;
} 
