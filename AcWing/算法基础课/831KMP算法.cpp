#include<iostream>
#include<string>
using namespace std;
// 好好复习！！！ 
int nextP[100010];
char P[100010],S[1000010];
int len1,len2;

int main(){
	int i,j;
	cin>>len1;
	cin>>P+1; //模式串 
	cin>>len2;
	cin>>S+1; //主串
	
	nextP[1] = 0;
	
	// 生成next数组 
	for(i=2,j=0;i<=len1;i++){
		while(j>0&&P[i]!=P[j+1]){
			j = nextP[j];
		}
		if(P[i]==P[j+1]) j++;
		nextP[i] = j;
	}
	
	for(i=1,j=0;i<=len2;i++){
		while(j>0&&S[i]!=P[j+1]) j = nextP[j];
		if(S[i]==P[j+1]) j++;
		if(j==len1){
			// 找到一个匹配位置
			cout<<i - len1<<" ";
			// 寻找下一个匹配位置 
			j = nextP[j];
		}
	}
	
	return 0;
} 
