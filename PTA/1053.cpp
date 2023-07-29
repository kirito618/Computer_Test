#include<bits/stdc++.h>
using namespace std;

int N,M,S;

int w[101];
vector<int> neighbor[101];
vector<int> tempVia;
// ��¼��ȷ·�����±�
vector<int> resultVia[101];

int viaId = 0;

bool comp(vector<int> a,vector<int> b){
	int i;
	int minSize = a.size()<b.size()?a.size():b.size();
	for(i=0;i<minSize-1;i++){
		if(a[i]!=b[i]) break;
	}
	if(i<minSize-1){
		if(a[i]>b[i]){
			return true;
		}
		return false;
	}else{
		return false;
	}
}

bool comp2(int a,int b){
	return w[a]>w[b];
}

// ·���ļ�¼������ 
void dfs(int cur,int weight){
	tempVia.push_back(w[cur]);
	if(neighbor[cur].size()==0){
		//��Ҷ�ӽڵ�
		if(weight==S){
			//����һ���ﵽҪ���·�� ��¼�±� 
			for(int x:tempVia){
				resultVia[viaId].push_back(x);
			}
			viaId++;
		}
		return ;
	}
	
	if(weight>S){
		// ˵����ǰ����Ҷ�ӽڵ� 
		//����ǰ�ۼ�Ȩ�ض��Ѿ�����Ҫ����,û�б�Ҫ������ȥ��
		return ;
	} 
	for(int next:neighbor[cur]){
		dfs(next,weight+w[next]);
		tempVia.pop_back();
	}
	
}

int main(){
	int root,temp,tempNode;
	cin>>N>>M>>S;
	for(int i=0;i<N;i++) cin>>w[i];
	for(int i=0;i<M;i++){
		cin>>root>>temp;
		for(int j=0;j<temp;j++){
			cin>>tempNode;
			neighbor[root].push_back(tempNode);
		}
		sort(neighbor[root].begin(),neighbor[root].end(),comp2);
	}
	
	dfs(0,w[0]);
	sort(resultVia,resultVia+viaId,comp);
	
	for(int i=0;i<viaId;i++){
		for(int j=0;j<resultVia[i].size();j++){
			cout<<resultVia[i][j];
			if(j==resultVia[i].size()-1) cout<<endl;
			else cout<<" ";
		}
	}
	
	return 0;
} 
