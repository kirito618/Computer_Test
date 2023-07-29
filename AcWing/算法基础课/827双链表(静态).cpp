#include<iostream>
#include<string>
using namespace std;

int M;
int value[100010];// �±����������k
int nextP[100010] = {-1},last[100010] = {-1};
int k=0;
int l=0,r=0;
int num = 0;

// �ڵ�t���������ǰ�����һ���� 
void insertLeft(int t,int v){
	int q = last[t];
	value[++k] = v;
	last[k] = q;
	nextP[k] = t;
	last[t] = k;
	nextP[q] = k;
	if(t==l){
		l = k;
	}
	num++;
}

// �ڵ�t����������������һ���� 
void insertRight(int t,int v){
	int q = nextP[t];//�õ���һ���ڵ�
	value[++k] = v;
	nextP[k] = q;
	last[k] = t;
	nextP[t] = k;
	last[q] = k;
	if(t==r){
		r = nextP[t];
	}
	num++;
}

void del(int t){
	int pre,post;
	pre = last[t];
	post = nextP[t];
	nextP[pre] = post;
	last[post] = pre;
	if(t==r){
		r = pre;
	}else if(t==l){
		l = post;
	}
	num--;
}

int main(){
	string op;
	int val,t;
	cin>>M;
	
	while(M--){
		cin>>op;
		if(op[0]=='L'){
			// ����˲�����
			cin>>val;
			value[++k] = val;
			if(l!=0){
				// ���Ѿ�������һ����
				nextP[k] = l;
				last[l] = k;
			}
			last[k] = -1;
			l = k;
			num++;
			if(num==1) r = k; 
		}else if(op[0]=='R'){
			//���Ҷ˲����� 
			cin>>val;
			value[++k] = val;
			nextP[k] = -1;
			if(r>0){
				last[k] = r;
				nextP[r] = k;
			}
			r = k;
			num++;
			if(num==1) l = k;
		}else if(op[0]=='D'){
			// ����k���������ɾ��
			cin>>t;
			del(t);
		}else{
			if(op[1]=='L'){
				// �ڵ�k���������������һ����
				cin>>t>>val; 
				insertLeft(t,val);
			}else{
				// �ڵ�k����������Ҳ����һ����
				cin>>t>>val;
				insertRight(t,val);
			}
		} 
	}
	
	while(nextP[l]!=-1){
		cout<<value[l]<<" ";
		l = nextP[l];
	}
	cout<<value[l]<<endl;
	
	return 0;
}
