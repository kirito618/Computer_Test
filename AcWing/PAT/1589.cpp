#include<bits/stdc++.h>

using namespace std;

int N;
int l[110],r[110],root[110],values[110];
int cnt;
int q[110];

void build(int rt){
	if(l[rt]!=-1) build(l[rt]);
	
	root[rt] = values[cnt++];
	
	if(r[rt]!=-1) build(r[rt]);
}

int main(){
	int a,b,x;
	int cnt2=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		l[i] = a;
		r[i] = b;
	}
	
	for(int i=0;i<N;i++) cin>>values[i];
	// 将序列排成递增,即按照二叉搜索树的中序特点来填数 
	sort(values,values+N);
	// 按中序遍历顺序挨个填入数值 
	build(0);
	
	x = 0;
	cnt2 = 0;
	q[0] = 0;
	while(x<N){
		if(l[q[x]]!=-1) q[++cnt2] = l[q[x]];
		if(r[q[x]]!=-1) q[++cnt2] = r[q[x]];
		x++;
	}
	
	cout<<root[q[0]];
	for(int i=1;i<N;i++){
		cout<<" "<<root[q[i]];
	}
	cout<<endl;
	
	return 0;
} 
