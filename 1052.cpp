#include<bits/stdc++.h>
using namespace std;

string address[100000];
long values[100000];
int indexs[100000];
string next_p[100000];
int N,l,r,k;
string k_add;
set<string> nexts;

bool cmp(int a,int b){
	return values[a]<values[b];
}

int main(){
	string begin;
	bool valid;
	int invalid_count = 0; 
	int j;
	cin>>N>>begin;
	if(begin=="-1"){
		cout<<"0 -1"<<endl;
		return 0;
	}
	nexts.insert(begin);
	for(int i=0;i<N;i++){
		cin>>address[i]>>values[i]>>next_p[i];
		nexts.insert(next_p[i]);
		// 记录下标
		indexs[i] = i;
	}
	
	// 下面要找出不合法的点并挪出链表范围(不在链表里，是孤立点)
	for(int i=0;i<N;i++){
		// 默认是无效点 
		valid = false;
		// set.count() 会返回该元素在集合中的个数，可以用来判断是否存在特定元素！ 
		if(next_p[i]==begin){
			valid = false;
		}else if(nexts.count(address[i])){
			//存在此元素，该元素就是有效点 
			valid = true; 
		}
		
		if(!valid){
			// 如果i是无效点，那么我们把他的key设置成最大，让他排序的时候跑到最后面去
			invalid_count++;
			values[i] = 100001; 
		}
	}
	
	// 将下标按照下标对应的key进行递增的排序 
	sort(indexs,indexs+N,cmp);
	N = N-invalid_count;
	
	cout<<N<<" "<<address[indexs[0]]<<"\n";
	for(j=0;j<N-1;j++){
		cout<<address[indexs[j]]<<" "<<values[indexs[j]]<<" "<<address[indexs[j+1]]<<"\n";
	}
	if(j==N-1) cout<<address[indexs[j]]<<" "<<values[indexs[j]]<<" -1";
	return 0;
}
