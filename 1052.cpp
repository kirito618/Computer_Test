#include<bits/stdc++.h>
using namespace std;

string address[100000];
long values[100000];
int indexs[100000];
string next_p[100000];
int N,l,r,k;
string k_add;
set<string> nexts;

bool cmp(int a,int b){
	return values[a]<values[b];
}

int main(){
	string begin;
	bool valid;
	int invalid_count = 0; 
	int j;
	cin>>N>>begin;
	if(begin=="-1"){
		cout<<"0 -1"<<endl;
		return 0;
	}
	nexts.insert(begin);
	for(int i=0;i<N;i++){
		cin>>address[i]>>values[i]>>next_p[i];
		nexts.insert(next_p[i]);
		// ��¼�±�
		indexs[i] = i;
	}
	
	// ����Ҫ�ҳ����Ϸ��ĵ㲢Ų������Χ(����������ǹ�����)
	for(int i=0;i<N;i++){
		// Ĭ������Ч�� 
		valid = false;
		// set.count() �᷵�ظ�Ԫ���ڼ����еĸ��������������ж��Ƿ�����ض�Ԫ�أ� 
		if(next_p[i]==begin){
			valid = false;
		}else if(nexts.count(address[i])){
			//���ڴ�Ԫ�أ���Ԫ�ؾ�����Ч�� 
			valid = true; 
		}
		
		if(!valid){
			// ���i����Ч�㣬��ô���ǰ�����key���ó�������������ʱ���ܵ������ȥ
			invalid_count++;
			values[i] = 100001; 
		}
	}
	
	// ���±갴���±��Ӧ��key���е��������� 
	sort(indexs,indexs+N,cmp);
	N = N-invalid_count;
	
	cout<<N<<" "<<address[indexs[0]]<<"\n";
	for(j=0;j<N-1;j++){
		cout<<address[indexs[j]]<<" "<<values[indexs[j]]<<" "<<address[indexs[j+1]]<<"\n";
	}
	if(j==N-1) cout<<address[indexs[j]]<<" "<<values[indexs[j]]<<" -1";
	return 0;
}
