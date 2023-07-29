#include<bits/stdc++.h>
using namespace std;

int N;
int tree[1010];
int com_tree[1010];
int pnt;

// ��������� ��������������ÿ��ֵ������ȫ������ 
void inorder(int root){
	// ������
	if(2*root<=N){
		inorder(2*root);
	}
	// ���ø��ڵ� 
	com_tree[root] = tree[pnt++];
	// ������ 
	if(2*root+1<=N){
		inorder(2*root+1);
	}
}


int main(){
	cin>>N;
	for(int i=1;i<=N;i++) cin>>tree[i];
	
	// ���ö������������ص�,��������ǵ����� 
	sort(tree+1,tree+N+1);
	
	pnt = 1;
	inorder(1);
	
	cout<<com_tree[1];
	for(int i=2;i<pnt;i++) cout<<" "<<com_tree[i];
	cout<<endl;
	
	return 0;
}
