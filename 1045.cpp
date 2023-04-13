#include<iostream>
using namespace std;

int N,L,F,j,k,begin_index,temp_index;
int favor[201];
int stripe[10000]; 
// 记录每个数字的个数 
int count_map[201];
int index_map[201];
int max_count = -1;
int temp_count;
int result;
int next_index;
bool flag;

// 记录每个favor数字结尾所能拿到的最大长度 
int max_length[201];

int main(){
	// 数据输入 
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
			//不是favor，跳过
			continue; 
		}
		// 是favor
		// 找到能够以当前favor作为结尾的最大长度 
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
