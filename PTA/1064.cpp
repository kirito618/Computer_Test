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
				//这个节点没访问过，可以考虑
				
			}
		}
		//只有这一层满了，才能往下一层走(2的level次方)
		if(){
			
		}
		if(have_left){
			//有左子树才去考虑右子树，如果没有左子树就要构建右子树
			
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
