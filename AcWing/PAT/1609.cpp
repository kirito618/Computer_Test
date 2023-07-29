#include<iostream>
#include<string>
using namespace std;

int N;
int pre[40],post[40];

// 暴搜树的方案，返回方案数 
int dfs(int l1,int r1,int l2,int r2,string &in){
	int cnt=0;
	if(l1>r1){
		// 说明该子树为空，也算一种方案
		return 1; 
	}
	if(pre[l1]!=post[r2]){
		// 前序的第一个点是根节点,后序的最后一个是根节点
		// 二者不一样,说明这个树不成立
		return 0; 
	}
	
	for(int i=l1;i<=r1;i++){
		// 大区间满足树的要求,接下来枚举左右子区间
		// 即l1是满足条件的,接下来在前序遍历中枚举它的左右子树区间 
		string lin="",rin="";
		// 计算当前左右子区间方案数
		// i=l1开始,保证的是第一个方案是没有左子树 
		int lcnt = dfs(l1+1,i,l2,l2+i-l1-1,lin);
		int rcnt = dfs(i+1,r1,l2+i-l1-1+1,r2-1,rin);
		// 因为l1是符合条件的,所以才枚举它的左右子树
		// 所以要把l1的字符加到结果里
		if(lcnt && rcnt){
			in = lin + to_string(pre[l1]) + " " + rin;
			cnt += lcnt*rcnt;
		}
		if(cnt>1) break;
	} 
	return cnt;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>pre[i];
	for(int i=0;i<N;i++) cin>>post[i];
	string result;
	// 可能的树的数量 刚开始前序和后序的区间是一样的 
	int count = dfs(0,N-1,0,N-1,result);
	if(count>1) puts("No");
	else puts("Yes");
	
	// 最后一个字符是空格,直接弹出 
	result.pop_back();
	cout<<result<<endl;
	
	return 0;
}
