#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 已经AC！ 

int N,pnt;
int l[100],r[100],q[100];
int inorder[100];

int find(int cur){
	int num = 1;
	if(l[cur]!=-1) num+=find(l[cur]);
	if(r[cur]!=-1) num+=find(r[cur]);
	return num;
}

void dfs(int cur){
	int t;
	// 交换左右子树 
	t = l[cur];
	l[cur] = r[cur];
	r[cur] = t;
	
	if(l[cur]!=-1) dfs(l[cur]);
	inorder[pnt++] = cur;
	if(r[cur]!=-1) dfs(r[cur]);
}

void bfs(int root){
	int hh=0,tt=0;
	q[0] = root;
	while(hh<=tt){
		if(l[q[hh]]!=-1){
			q[++tt] = l[q[hh]];
		}
		if(r[q[hh]]!=-1){
			q[++tt] = r[q[hh]];
		}
		hh++;
	}
	cout<<q[0];
	for(int i=1;i<N;i++) cout<<" "<<q[i];
	cout<<endl;
}

int main(){
	string a,b;
	int temp;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		if(a=="-") l[i] = -1;
		else l[i] = a[0] - '0';
		if(b=="-") r[i] = -1;
		else r[i] = b[0] - '0';
	}
	
	int root=0;
	for(int i=0;i<N;i++){
		temp = find(i);
		if(temp==N){
			root = i;
			break;
		}
	}
	dfs(root);
	bfs(root);
	
	cout<<inorder[0];
	for(int i=1;i<N;i++) cout<<" "<<inorder[i];
	cout<<endl;
	
	return 0;
}
