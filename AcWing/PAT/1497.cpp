#include<bits/stdc++.h>

using namespace std;
int N;

int inorder[40];
int postorder[40];
// �洢���������Ԫ��������������Ӧ���±� 
unordered_map<int,int> post_in_mid;
// �洢ÿ���ڵ�����������ĸ��ڵ� 
unordered_map<int,int> l_son,r_son;

// ����������� 
int q[40];

// �ݹ齨��,����ֵΪ���ڵ� 
int build(int il,int ir,int pl,int pr){
	// ÿ�����ڵ㶼�������������ĺ�����������һ��ֵ 
	int root = postorder[pr];
	// ȡ�ø��ڵ�����������е��±� 
	int k = post_in_mid[root];
	if(il<k){
		// ˵������������
		// pl+(k-1-il) �� ��Ϊ�����������Ǻ��������ڵ������һ����
		// ��ô���䳤��Ҳ��һ���ģ����Ƶ������� 
		l_son[root] = build(il,k-1,pl,pl+(k-1-il));
	}
	if(k<ir){
		// ����������
		r_son[root] = build(k+1,ir,pl+(k-1-il)+1,pr-1); 
	}
	return root; 
}

// ����������� 
void bfs(int root){
	// ��βָ�� 
	int hh=0,tt=0;
	int t;
	q[0] = root;
	while(hh<=tt){
		// �õ���ǰ���׵ĸ��ڵ� ȡ������ָ����� 
		t = q[hh++];
		// ���������map����keyֵΪ��ǰ���ڵ�
		// ˵���ýڵ��������� 
		if(l_son.count(t)) q[++tt] = l_son[t];
		if(r_son.count(t)) q[++tt] = r_son[t];
	}
	
	cout<<q[0];
	for(int i=1;i<N;i++) cout<<" "<<q[i];
	cout<<endl;
} 

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>postorder[i];
	for(int i=0;i<N;i++){
		cin>>inorder[i];
		// ��¼�±� 
		post_in_mid[inorder[i]] = i;
	}
	
	int root = build(0,N-1,0,N-1);
	
	// ������� ������ 
	bfs(root);
	
	return 0;
}
