#include<iostream>
#include<vector>
using namespace std;

int N,temp,two;
vector<int> all_nodes;
vector<int> levels[1000];
int two_right[10];
bool have_left,have_right;
bool visited[1000];
int leftIndex,rightIndex;

void buildTree(int nodeIndex,int rootIndex,int level){
	visited[nodeIndex] = true;
	have_left = false;
	have_right = false;
	if(levels[level].size()==two_right[level]){
		for(int i=0;i<all_nodes.size();i++){
			if(!visited[i]){
				//����ڵ�û���ʹ������Կ���
				
			}
		}
		//ֻ����һ�����ˣ���������һ����(2��level�η�)
		if(){
			
		}
		if(have_left){
			//����������ȥ���������������û����������Ҫ����������
			
		}
		buildTree();
	}
}

int main(){
	two = 1;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>temp;
		all_nodes.push_back(temp);
	}
	
	for(int i=0;i<10;i++){
		two_right[i] = two;
		two = two*2;
	}
	
	
	return 0;
}
