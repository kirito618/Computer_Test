#include<bits/stdc++.h>
using namespace std;
int p[100010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int n,m,a,b;
	char opt;
	cin>>n>>m;
	// �������Լ����Լ���һ������ 
	for(int i=1;i<=n;i++) p[i] = i;
	
	for(int i=0;i<m;i++){
		cin>>opt>>a>>b;
		if(opt=='M'){
			// �ϲ������� 
			if(find(a)!=find(b)){
				// ���߲���ͬһ��������
				p[find(a)] = find(b); 
			}
		}else if(opt == 'Q'){
			// ��ѯ�����Ƿ���ͬһ����������
			if(find(a)!=find(b)) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	return 0;
}
