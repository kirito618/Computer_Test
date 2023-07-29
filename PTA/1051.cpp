#include<iostream>
#include<string>
using namespace std;

//M为栈长度 
int M,N,K; 
int buffer[1000][1000];

int main(){
	bool flag;
	cin>>M>>N>>K;
	for(int i=0;i<K;i++){
		for(int j=0;j<N;j++){
			cin>>buffer[i][j];
		}
	} 
	
	for(int i=0;i<K;i++){
		flag = true;
		for(int j=0;j<N;j++){	
			if(buffer[i][j]>(M+j)){
				// 说明这个序号不应该出现在栈里
				flag = false;
				break;
			}
			if(buffer[i][j+1]<buffer[i][j]+1){
				//如果下一个序号并不是当前序号的下一个
				//说明当前序号入栈后没有立刻出栈 
				for(int x=j+2;x<N;x++){
					if(buffer[i][x]==buffer[i][j]-1){
						flag = false;
//						cout<<buffer[i][j]<<" "<<buffer[i][x]<<endl; 
						break;
					}
				}
			}
			
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
