#include<iostream>
#include<string>
using namespace std;

int N;
int pre[40],post[40];

// �������ķ��������ط����� 
int dfs(int l1,int r1,int l2,int r2,string &in){
	int cnt=0;
	if(l1>r1){
		// ˵��������Ϊ�գ�Ҳ��һ�ַ���
		return 1; 
	}
	if(pre[l1]!=post[r2]){
		// ǰ��ĵ�һ�����Ǹ��ڵ�,��������һ���Ǹ��ڵ�
		// ���߲�һ��,˵�������������
		return 0; 
	}
	
	for(int i=l1;i<=r1;i++){
		// ��������������Ҫ��,������ö������������
		// ��l1������������,��������ǰ�������ö������������������ 
		string lin="",rin="";
		// ���㵱ǰ���������䷽����
		// i=l1��ʼ,��֤���ǵ�һ��������û�������� 
		int lcnt = dfs(l1+1,i,l2,l2+i-l1-1,lin);
		int rcnt = dfs(i+1,r1,l2+i-l1-1+1,r2-1,rin);
		// ��Ϊl1�Ƿ���������,���Բ�ö��������������
		// ����Ҫ��l1���ַ��ӵ������
		if(lcnt && rcnt){
			in = lin + to_string(pre[l1]) + " " + rin;
			cnt += lcnt*rcnt;
		}
		if(cnt>1) break;
	} 
	return cnt;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>pre[i];
	for(int i=0;i<N;i++) cin>>post[i];
	string result;
	// ���ܵ��������� �տ�ʼǰ��ͺ����������һ���� 
	int count = dfs(0,N-1,0,N-1,result);
	if(count>1) puts("No");
	else puts("Yes");
	
	// ���һ���ַ��ǿո�,ֱ�ӵ��� 
	result.pop_back();
	cout<<result<<endl;
	
	return 0;
}
