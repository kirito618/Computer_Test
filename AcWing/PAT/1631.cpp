#include<iostream>
#include<unordered_map>
using namespace std;
// PAT��AC��,Acwing ���� 

int N;
unordered_map<int,int> pre_in_in;

// ��¼����ڵ��������е��±� 
int pre[50005],ino[50005],post[2];
int cnt;

void find(int pl,int pr,int il,int ir){
	if(cnt==1) return ;
	int root = pre[pl];
	int i = pre_in_in[root];
	// �������ݹ�
	if(il<i) find(pl+1,pl+i-il,il,i-1);
	// �������ݹ� 
	if(i<ir) find(pl+i-il+1,pr,i+1,ir);
	// ��¼���ڵ� 
	post[cnt++] = root;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>pre[i];
	for(int i=0;i<N;i++){
		cin>>ino[i];
		pre_in_in[ino[i]] = i;
	}
	find(0,N-1,0,N-1);
	cout<<post[0]<<endl;
	
	
	return 0;
}
