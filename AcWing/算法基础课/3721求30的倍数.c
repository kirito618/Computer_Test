#include<stdio.h>
#include<string.h>
int res=-1,len;
char input[10],temp[10],st[10];

int to_int(){
	int res = 0,i;
	for(i=0;i<len;i++){
		res = res*10 + (temp[i]-'0');
	}
	//printf("%d\n",res);
	return res;
}

void dfs(int cur){
	if(cur==len){
		// 已经组合出一种了
		int t = to_int();
		if(t>res&&t%30==0) res = t;
		return ; 
	}
	int i;
	for(i=0;i<len;i++){
		if(st[i]!=1){
			st[i] = 1;
			temp[cur] = input[i];
			dfs(cur+1);
			st[i] = 0;
		}
	}
}

int main(){
	scanf("%s",input);
	len = strlen(input);
	dfs(0);
	printf("%d\n",res);
	return 0;
} 
