#include<iostream>
#include<string>
using namespace std;

//MΪջ���� 
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
				// ˵�������Ų�Ӧ�ó�����ջ��
				flag = false;
				break;
			}
			if(buffer[i][j+1]<buffer[i][j]+1){
				//�����һ����Ų����ǵ�ǰ��ŵ���һ��
				//˵����ǰ�����ջ��û�����̳�ջ 
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
