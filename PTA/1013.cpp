#include<iostream>
#include<vector>
using namespace std;
vector<int> map[1001];
// lost ��ʾ���Ǳ�ռ����Ǹ��� 
int N,M,K,lost;
bool visited[1000]; 

// �жϴ�from��to�Ƿ�ɴ� 
void dfs(int cur){
	//�ѵ�ǰ����Ϊ�ѷ��� 
	visited[cur] = true;
	
	for(int i:map[cur]){
		//�Ե�ǰ�������ڵ�����δ������δ��ռ��ĵ㶼����������ȱ���
		if((!visited[i])&&(i!=lost)){
		    dfs(i);
	    }
	}
	
}

int main(){
	int i,j,k,l;
	int num;
	
	cin>>N>>M>>K;
	// ͼ�Ľ��� 
	for(i = 0;i < M;i++){
		cin>>j>>l;
		// ����ͼ����ʾ������ͨ�� 
		map[j].push_back(l);
		map[l].push_back(j);
	}
	
	// ����������K�����ܱ�ռ��ĵ㣬ÿ���㶼���д���
	// ������ͨ��ͼ�ĸ�����Ȼ����ͼ����-1��������Ҫ�޲���·�ĸ���
	
	for(j=0;j<K;j++){
		// ��ͨ��ͼ������Ϊ0 
		num = 0;
		cin>>lost;
		for(i=1;i<=N;i++)visited[i] = false;
		for(i=1;i<=N;i++){
			if((i!=lost) && (!visited[i])){
				//��ǰ��û�����ʹ�����û��ռ�죬��ô�Ϳ�����һ����ͨ��ͼ�Ŀ�ʼ��
				num++;
				//�Ѵ�����ڵ�����ܵ�������е�ȫ����Ϊ�ѷ��� 
				dfs(i);
			}
		}
		// ��¼�·ֱ���Ҫ����·��
		map[1000].push_back(num-1);
	}

	for(int result:map[1000]){
		cout<<result<<endl;
	}
	return 0;
}
