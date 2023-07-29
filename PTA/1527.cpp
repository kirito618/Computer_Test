#include<bits/stdc++.h>

int result[1010];
int preorder[1010],inorder[1010],postorder[1010];
int cnt,N;


bool build(int pl,int pr,int il,int ir,int type){
	if(il>ir){
		// û�нڵ�,�ǵ�Ȼ���Խ���������
		return true;
	}
	// ��������ĵ�һ�����Ǹ��ڵ� 
	int root = preorder[pl];
	int k;
	bool res = true;
	if(type==0){
		// �ҵ���������е�һ�γ��ָø��ڵ��λ��
		// �������������,�Ҳ��������� 
		for(k=il;k<=ir;k++){
			if(root==inorder[k]){
				break;
			}
		}
		if(k>ir) return false;
	}else{
		// �ҵ���������е�һ�γ��ָø��ڵ��λ��
		// �������������,�Ҳ��������� 
		for(k=ir;k>=il;k--){
			if(root==inorder[k]){
				break;
			}
		}
		if(k<il) return false;
	}
	if(!build(pl+1,pl+k-il,il,k-1,type)) res = false;
	if(!build(pr-ir+k+1,pr,k+1,ir,type)) res = false;
	
	// ��¼����������
	postorder[cnt++] = root; 
	return res;
}

using namespace std;
int main(){
	scanf("%d",&N);
	// ���������� 
	for(int i=0;i<N;i++){
		scanf("%d",&preorder[i]);
		inorder[i] = preorder[i];
	}
	
	// ������������ 
	sort(inorder,inorder+N);
	
	if(build(0,N-1,0,N-1,0)){
		puts("YES");
		cout<<postorder[0];
		for(int i=1;i<cnt;i++){
			cout<<" "<<postorder[i];
		}
		cout<<endl;
	}else{
		// ԭ����������,��ô�Ͱ�Ҫ����о���(������������) 
		reverse(inorder,inorder+N);
		cnt = 0; 
		if(build(0,N-1,0,N-1,1)){
			puts("YES");
			cout<<postorder[0];
			for(int i=1;i<cnt;i++){
				cout<<" "<<postorder[i];
			}
			cout<<endl;
		}else{
			puts("NO");
		}
	}
	
	return 0;
}
