#include<iostream>
using namespace std;

// �ȵ���ѧѧ������
 

int N,cnt;
// v,l,rģ����,h�洢ÿ���ڵ�ĸ߶� 
int v[30],l[30],r[30],h[30];
// ����x�Žڵ�ĸ߶� 
void update(int x){
	// x�ĸ߶ȵ����������Ҷ��ӵĸ߶����ֵ+1 
	h[x] = max(h[l[x]],h[r[x]]) + 1;
}
// ����x�Žڵ����������ĸ߶Ȳ� 
int sub_height(int x){
	return h[l[x]] - h[r[x]];
}

// ��x�ŵ��������,�������µĸ��ڵ� 
int turn_left(int x){
	int p = r[x];
	r[x] = l[p];
	l[p] = x;
	// �ȸ��¶���,�ڸ����µĸ��ڵ� 
	update(x); 
	update(p);
	return p;
}

// ��x���������,�������µĸ��ڵ� 
int turn_right(int x){
	// �����Ļ�һ���Ǹ��ڵ������ӵ��µĸ��ڵ� 
	int p = l[x];
	// ����ӳ�Ϊ���ڵ������ӵ��Ҷ�����ԭ���ĸ��ڵ�
	// ԭ���ĸ��ڵ������ӿճ����ˣ�ǡ�ô���¸��ڵ���Ҷ��� 
	l[x] = r[p];
	r[p] = x;
	// ���¶��ߵĸ߶� �ȸ��¶���,�ڸ����µĸ��ڵ� 
	update(x);
	update(p);
	return p;
} 

// ����ֵΪx�Ľڵ�,�������µĸ��ڵ� 
int insert(int root,int x){
	if(root == -1) {
		v[cnt] = x;
		root = cnt++;
	}
	else if(x<v[root]){
		// ���ն����������Ĺ���Ӧ�ò��뵽��������
		root = insert(l[root],x);
		if(sub_height(root)==2){
			//���������߶Ȳ���+2,˵������
			if(sub_height(l[root])==1){
				// ������������������������,�������ڵ�
				root = turn_right(root); 
			}else{
				// �����������,���������ڵ�
				l[root] = turn_left(l[root]); 
				root = turn_right(root);
			}
		}
	}else{
		// ��������
		root = insert(r[root],x);
		if(sub_height(root)==-2){
			//���������߶Ȳ���-2,˵���Ҳ��
			if(sub_height(r[root])==-1){
				// ������������������������,�������ڵ�
				root = turn_left(root); 
			}else{
				// �������Ҷ���,���������ڵ�
				r[root] = turn_right(r[root]); 
				root = turn_left(root);
			}
		}
	}
	update(root);
	return root;
}

int main(){
	// root������ǵ�ǰ���ڵ���±�,�ǲ����ڸı�� 
	int root = -1; 
	cin>>N;
	for(int i=0;i<N;i++){
		l[i]=-1;
		r[i]=-1;
		v[i]=-1;
	}
	for(int i=0;i<N;i++){
		cin>>v[cnt];
		root = insert(root,v[cnt]);
		cout<<h[root]<<endl;
	}
	cout<<v[root]<<endl;
	return 0;
}
