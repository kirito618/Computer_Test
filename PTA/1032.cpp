#include<iostream>
#include<cstdio>
using namespace std;

// �±��ǵ�ַ ֵ�ǽڵ��ֵ 
char nodes[100000];
// �±��ǵ�ַ ֵ������ڵ��nextȡֵ 
int nexts[100000];

int N,beginIndex1,beginIndex2;
// ��¼ÿ���ڵ�ĵ�ַ�����˶��ٴ� 
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
	
	//�ȴ�һ�Ŷ� 
	while(nexts[x]!=-1){
		count_node[x]++;
		x = nexts[x];
	}

	//����Ŷ�
	while(nexts[y]!=-1&&nexts[y]!=0){
		if(count_node[y]!=0){
			//˵���˽ڵ�ĵ�ַҲ�����ڵ�һ��������
			printf("%05d",y);
			return 0;
		}
		count_node[y]++;
		y = nexts[y];
	}
	
	cout<<"-1"<<endl;
	
	return 0;
} 
