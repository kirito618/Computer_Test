#include<iostream>
#include<string>
using namespace std;
// �úø�ϰ������ 
int nextP[100010];
char P[100010],S[1000010];
int len1,len2;

int main(){
	int i,j;
	cin>>len1;
	cin>>P+1; //ģʽ�� 
	cin>>len2;
	cin>>S+1; //����
	
	nextP[1] = 0;
	
	// ����next���� 
	for(i=2,j=0;i<=len1;i++){
		while(j>0&&P[i]!=P[j+1]){
			j = nextP[j];
		}
		if(P[i]==P[j+1]) j++;
		nextP[i] = j;
	}
	
	for(i=1,j=0;i<=len2;i++){
		while(j>0&&S[i]!=P[j+1]) j = nextP[j];
		if(S[i]==P[j+1]) j++;
		if(j==len1){
			// �ҵ�һ��ƥ��λ��
			cout<<i - len1<<" ";
			// Ѱ����һ��ƥ��λ�� 
			j = nextP[j];
		}
	}
	
	return 0;
} 
