#include<iostream>
#include<cstdio>
using namespace std;

// 下标是地址 值是节点的值 
char nodes[100000];
// 下标是地址 值是这个节点的next取值 
int nexts[100000];

int N,beginIndex1,beginIndex2;
// 记录每个节点的地址出现了多少次 
int count_node[100000];

int count_A=0,count_B=0;
int main(){
	int add,next,x,y;
	int beginIndex=-1;
	char key;
	cin>>beginIndex1>>beginIndex2>>N;
	x = beginIndex1;
	y = beginIndex2;
	for(int i=0;i<N;i++){
		cin>>add>>key>>next;
		nodes[add] = key;
		nexts[add] = next;
	}
	
	//先存一号队 
	while(nexts[x]!=-1){
		count_node[x]++;
		x = nexts[x];
	}

	//存二号队
	while(nexts[y]!=-1&&nexts[y]!=0){
		if(count_node[y]!=0){
			//说明此节点的地址也被存在第一条队列里
			printf("%05d",y);
			return 0;
		}
		count_node[y]++;
		y = nexts[y];
	}
	
	cout<<"-1"<<endl;
	
	return 0;
} 
