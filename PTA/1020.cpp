#include<iostream>
#include<vector> 
using namespace std;
int N;
//order[0]������Ǻ���order[1]�����������
vector<int> order[2];
vector<int> tree[31];
int postIndex[31];
int inIndex[31];
int left_length,right_length;

// s1,e1 �ֱ��Ǻ�������������ʼ�±�ͽ����±꣬����ͬ������������� 
void dfs(int s1,int e1,int s2,int e2,int level){
	if(s1>e1) return;
	// ���������������һ��ֵһ������������ĸ��ڵ� 
	int result = order[0][e1];
	// ������������Ӧ����ȥ 
	tree[level].push_back(result);
	// ����������
	// �������ں��������������Ҷ˵�δ֪��Ҫ����˵��±�+���� -1 
	dfs(s1, s1+inIndex[result]-1-s2,s2,inIndex[result]-1,level + 1);
	// ����������,�����������ں���������������˵�δ֪��Ҫ���Ҷ˵��±� -����
	dfs(inIndex[result]+e1-e2, e1-1 ,inIndex[result]+1,e2,level + 1);
}


int main(){
	int i,j,k,count;
	cin>>N;
	// �������������� 
	for(i=0;i<N;i++){
		cin>>j;
		// ��¼������ں��������е��±� 
		postIndex[j] = i; 
		order[0].push_back(j);
	}
	k = j;
	// ��������������� 
	for(i=0;i<N;i++){
		cin>>j;
		// ��¼����������������е��±�
		inIndex[j] = i;
		order[1].push_back(j);
	}
	
	// ������������һ�����һ�����ܸ��ڵ㣬���Գ�ʼ�±�ýڵ�������±� 
	k = inIndex[k];
	dfs(0,N-1,0,N-1,1);
	count = N;
	for(int level=1;level<=N;level++){
		
		for(int i=0;i<tree[level].size();i++){
			if(count!=N) cout<<" ";
			cout<<tree[level][i];
			count--;
		}
	}
	cout<<endl;
	return 0;
}
