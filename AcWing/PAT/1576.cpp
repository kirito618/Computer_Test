#include<bits/stdc++.h>
using namespace std;

int N;
stack<int> getResult,xx;
int inorder[40],preorder[40],postorder[40];
int cnt,cnt2,cnt3;
map<int,int> pre_in;

int build(int pl,int pr,int il,int ir){
	int root = preorder[pl];
	// �õ���������������±� 
	int k = pre_in[root];
	
	if(il<k){
		build(pl+1,pl+k-il,il,k-1);
	}
	if(k<ir){
		build(pr-(ir-k-1),pr,k+1,ir);
	}
	postorder[cnt3++] = root;
	return root;
}

// push�����õ������о�����������
// pop�������������о��Ǻ������� 

int main(){
	string op;
	int index,temp;
	cin>>N;
	for(int i=0;i<2*N;i++){
		cin>>op;
		if(op.length()==3){
			//pop
			temp = getResult.top();
			getResult.pop();
			pre_in[temp] = cnt;
			inorder[cnt++] = temp;
		}else{
			//push
			cin>>index;
			preorder[cnt2++] = index;
			getResult.push(index);
		}
	}
	
	build(0,N-1,0,N-1);
	cout<<postorder[0];
	for(int i=1;i<cnt3;i++){
		cout<<" "<<postorder[i];
	}
	cout<<endl;
	return 0;
}
