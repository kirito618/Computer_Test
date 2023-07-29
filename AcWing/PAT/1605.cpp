#include<iostream>
#include<vector>
using namespace std;
// PAT1115题 和 ACwing1605题均AC

int v[1010],l[1010],r[1010],input[1010];
int level_count[1010];
int N,cmt;
int max_level=0;

// 插入节点的函数
void embed(int root,int value,int level){
	max_level = max(max_level,level);
	if(value<=v[root]){
		if(l[root]==-1001){
			l[root] = cmt;
			v[cmt++] = value;
			level_count[level]++;
			return ;
		}else{
			embed(l[root],value,level+1);
		}
	}else{
		if(r[root]==-1001){
			r[root] = cmt;
			v[cmt++] = value;
			level_count[level]++;
			return ;
		}else{
			embed(r[root],value,level+1);
		}
	}
	
}

int main(){
	int a,b;
	cin>>N;
	
	if(N==1){
		cin>>v[0];
		cout<<"1 + 0 = 1"<<endl;
		return 0;
	}
	
	for(int i=0;i<N;i++){
		l[i]=-1001;
		r[i]=-1001;
	}
	// 第一个点是根节点 
	cin>>v[cmt++];
	
	for(int i=1;i<N;i++) cin>>input[i];
	
	for(int i=1;i<N;i++) embed(0,input[i],0);
	
	a = level_count[max_level];
	b = level_count[max_level-1];
	cout<<a<<" + "<<b<<" = "<<a+b;
}
