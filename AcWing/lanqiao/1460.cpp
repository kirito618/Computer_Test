#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;
string s;
int N;

// �����жϴ�ʱ��ȡֵ�Ƿ���������
// ������һ������Ϊmid���ִ����Ƕ�һ�޶��� 
bool valid(int mid){
	// ����һ����ϣ��  �������г���Ϊmid���Ӵ� 
	unordered_set<string> database;
	for(int i=0;i<=N-mid+1;i++){
		// ��ȡ����Ϊmid���ִ� 
		string son = s.substr(i,mid);
		if(database.count(son)){
			// ��ϣ�����Ѿ�����  ˵�����ظ����Ӵ�
			return false;
		}
		database.insert(son);
	}
	// ����û�з���  ˵��û���ظ��ĳ���Ϊmid���Ӵ� 
	return true;
	
}

int main(){
	int l,r,mid;
	cin>>N>>s;
	l = 0;
	r = N;
	
	// ���ֲ��� 
	while(l<r){
		// �����Ƕ���������һλ  �൱�ڳ���2 
		mid = (l+r)>>1;
		if(valid(mid)){
			// ���ֵ���� ��ô�𰸾������ֵ ���������ֵ�����
			// ��Ϊ���˵���ֵ�ܳ���  ��ô���д���mid���Ӵ�Ҳ���Ƕ�һ�޶���
			// �������ֵ��������������һ��ֵ ��������answer<=mid 
			r = mid; 
		}else{
			l = mid + 1;
		}
	}
	
	// �˳�ѭ��ʱl==r �����˭��һ�� 
	cout<<r<<endl;
	
	return 0;
}
