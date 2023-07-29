#include<iostream>

using namespace std;

int N;
int q[30],l[30],r[30];


// ACwing上过了  但是PAT差一个一分的测试点 
int dfs(int cur){
	int num = 1;
	if(l[cur]!=-1) num+=dfs(l[cur]);
	if(r[cur]!=-1) num+=dfs(r[cur]);
	return num;
}

int toInt(string x){
	int result = 0;
	for(int i=0;i<x.length();i++){
		result = result*10 + (x[i]-'0');
	}
	return result;
}

int main(){
	string a,b;
	int num,root,cnt=1;
	bool flag=true;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>a>>b;
		if(a[0]!='-') l[i] = toInt(a);
		else l[i] = -1;
		if(b[0]!='-') r[i] = toInt(b);
		else r[i] = -1;
	}
	
	// 寻找根节点 
	for(int i=0;i<N;i++){
		num = dfs(i);
		if(num==N){
			root = i;
			break;
		}
	}
	
	q[1] = root;
	for(int i=1;i<=N;i++){
		if(l[q[i]]!=-1) q[++cnt] = l[q[i]];
		if(r[q[i]]!=-1) q[++cnt] = r[q[i]];
	}
	
	for(int i=1;i<=N;i++){
		if(l[q[i]]!=-1&&l[q[i]]!=q[2*i]){
			flag = false;
			break;
		}
		if(r[q[i]]!=-1&&r[q[i]]!=q[2*i+1]){
			flag = false;
			break;
		}
	}
	
	if(!flag){
		cout<<"NO "<<root<<endl;
	}else{
		cout<<"YES "<<q[N]<<endl;
	}
	return 0;
}
