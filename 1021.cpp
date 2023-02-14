#include<iostream>
#include<vector>
using namespace std;
int N,temp1,temp2,lastIndex=0,lastLevel;
int count = 0; 
int max_level=0;
bool flag = false;
//levels[i] �������i��Ϊ�����ȵ����и��ڵ� 
vector<int> levels[10001];
vector<int> nodes[10001];
vector<int> alls[10001];
vector<int> results;
bool visited[10001];

void dfs2(int cur,int root,int level){
	if(level>max_level){
		max_level = level;
		results.clear();
		results.push_back(root);
		lastIndex = root;
	}else if(level == max_level&&lastIndex!=root){
		results.push_back(root);
		lastIndex=root;
	}
	
	visited[cur] = true;
	for(int i=0;i<nodes[cur].size();i++){
		temp1 = nodes[cur][i];
		if(!visited[temp1]){
			dfs2(temp1,root,level+1);
		}
	}
}

void find_son_graph(int cur){
	visited[cur] = true;
	//�����ڵ��Լ����굽������е㶼���Ϊ���ʹ� 
	for(int i=0;i<nodes[cur].size();i++){
		temp1 = nodes[cur][i];
		if(!visited[temp1]){
			find_son_graph(temp1);
		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N-1;i++){
		cin>>temp1>>temp2;
		nodes[temp1].push_back(temp2);
		nodes[temp2].push_back(temp1);
	}
	//��ʼ��
	count = 0;
	for(int i=1;i<=N;i++){
		visited[i] = false;
		//�����㣬������Ҳ��һ����ͨͼ�� 
		if(nodes[i].size()==0){
			visited[i] = true; 
			count++;
		}
	}
	
	temp1 = 1;
	while(temp1<=N){
		if((!visited[temp1])&&(nodes[temp1].size()>0)){
			find_son_graph(temp1);
			count++;
		}
		temp1++;
	}

	for(int i=1;i<=N;i++){
		visited[i] = false;
	}
	
	//�������ڶ����ͨ��ͼ����������
	if(count==1){
		//�ֱ���ÿһ������Ϊ���ڵ����������ȱ��� 
		for(int i=1;i<=N;i++){
			if(!visited[i])){
				dfs2(i,i,0);
				for(int j=1;j<=N;j++){
					visited[j] = false;
				}
			}
	  	}
	  	
 		for(int result:results){
 			cout<<result<<endl;
		 }
	}else{
		//��������м�����ͨ��ͼ
		cout<<"Error: "<<count<<" components"<<endl;
	}
	
	return 0;
}
