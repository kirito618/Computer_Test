#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int N,cnt;
// level记录第i层元素个数
int l[40],r[40],v[40],in[40],post[40],num_level[40];
int q[40];
int ind;
unordered_map<int,int> post_in;

int build(int il,int ir,int pl,int pr,int level){
	int root = post[pr];
	int i = post_in[root];
	int index = cnt;
	// 记录当前节点的值和层数 
	num_level[level]++;
	v[cnt++] = root;
	// 记录左儿子(前提是得有左儿子)
	if(il<i)
		l[index] = build(il,i-1,pl,pl+(i-1-il),level+1);
	// 记录右儿子(前提是得有右儿子)
	if(i<ir)
		r[index] = build(i+1,ir,pl+(i-1-il)+1,pr-1,level+1);
	
	return index;
}

void bfs(){
	// 指向当前指向的值 
	int point=0;
	q[ind++] = 0;
	while(ind<N){
		if(l[q[point]]!=-1){
			q[ind++] = l[q[point]];
		}
		if(r[q[point]]!=-1){
			q[ind++] = r[q[point]];
		}
		point++;
	}
	int left,right,temp_level=1,temp;
	string result = "";
	left = 0;
	while(num_level[temp_level]>0){
		right = left+num_level[temp_level]-1;
		if(temp_level%2!=0){
			for(int j=right;j>=left;j--)
				result=result+to_string(v[q[j]])+" ";
		}else{
			for(int i=left;i<=right;i++)
				result=result+to_string(v[q[i]])+" ";
		}
		left = right+1;
		temp_level++;
	}
	result.pop_back();
	cout<<result<<endl;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>in[i];
		post_in[in[i]] = i;
	} 
	for(int i=0;i<N;i++) cin>>post[i];
	for(int i=0;i<N;i++){
		l[i]=-1;
		r[i]=-1;
	}
	int root = build(0,N-1,0,N-1,1);
	bfs();
	return 0;
}
