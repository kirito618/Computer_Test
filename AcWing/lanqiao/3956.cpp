#include<iostream>
using namespace std;

// �Ѿ�AC 
long long n;
long long a[100000];
// ��¼���±�iΪ��β,��0Ϊ��ͷ������� 
long long sum[100000];
// ��¼���±�iΪ��β�ı��������ж��ٸ�ǰ׺��Ϊ S/3�� 
long long cnt[100000];
int main(){
	long long x,result = 0;
	long long first,second;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
			x = sum[i-1];
		}else{
			x = 0;
		}
		sum[i] = x + a[i];
	}
	
	if(sum[n-1]%3!=0||n<3){
		// ���ܻ��ֳ�����ӵ����ͬ�͵������� �޽�
		cout<<0<<endl;
		return 0; 
	}
	
	cnt[0] = sum[0]==sum[n-1]/3?1:0;
	
	for(int i=1;i<n;i++){
		if(sum[i]==sum[n-1]/3){
			// ˵����iΪ��β�ı������ڵĺ�Ϊ S/3
			// ��������1
			cnt[i] = cnt[i-1]+1; 
		}else{
			cnt[i] = cnt[i-1];
		}
	}
	
	for(int i=1;i<n-1;i++){
		if(sum[i]==2*sum[n-1]/3){
			//˵���˶˵����������Ϊ 2/3*S
			result += cnt[i-1];
		}
	}
	
	cout<<result<<endl;
	return 0;
}
