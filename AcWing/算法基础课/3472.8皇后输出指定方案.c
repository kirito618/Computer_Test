#include<stdio.h>
int queen[93][9],temp[9];
int cnt=1;

int check(int cur){
	int i;
	for(i=1;i<cur;i++){
		if(temp[i]==temp[cur]||abs(temp[i]-temp[cur])==abs(i-cur)){
			return 0;
		}
	}
	return 1;
}

void dfs(int cur){
	int i;
	if(cur==9){
		for(i=1;i<=8;i++){
			queen[cnt][i] = temp[i];
		}
		cnt++;
		return ;
	}
	// 每个皇后尝试8个位置 
	for(i=1;i<=8;i++){
		temp[cur] = i;
		if(check(cur)==1){
			dfs(cur+1);
		}
	}
}

int main(){
	int t,a,i;
	dfs(1);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		for(i=1;i<=8;i++) printf("%d",queen[a][i]);
		puts("");
	}
	
	return 0;
}
