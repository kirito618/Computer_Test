#include<iostream>
using namespace std;

int N,L,F,j,k,begin_index,temp_index;
int favor[201];
int stripe[10000]; 
// ��¼ÿ�����ֵĸ��� 
int count_map[201];
int index_map[201];
int max_count = -1;
int temp_count;
int result;
int next_index;
bool flag;

// ��¼ÿ��favor���ֽ�β�����õ�����󳤶� 
int max_length[201];

int main(){
	// �������� 
	cin>>N>>F;
	for(int i=0;i<201;i++) index_map[i] = 202;
	for(int i=0;i<F;i++){
		cin>>favor[i];
		count_map[favor[i]]++;
		index_map[favor[i]] = i;
	}
	cin>>L;
	for(int i=0;i<L;i++){
		cin>>stripe[i];
	} 
	
	for(int i=0;i<L;i++){
		if(count_map[stripe[i]]==0){
			//����favor������
			continue; 
		}
		// ��favor
		// �ҵ��ܹ��Ե�ǰfavor��Ϊ��β����󳤶� 
		max_count = 0;
		for(int j=0;j<=index_map[stripe[i]];j++){
			if(max_length[favor[j]]>max_count){
				max_count = max_length[favor[j]];
			}
		}
		max_count++;
		max_length[stripe[i]] = max_count;
	}
	
	result = -1;
	for(int i=0;i<F;i++){
		if(max_length[favor[i]]>result) result = max_length[favor[i]];
	}
	cout<<result<<endl;
	return 0;
} 
