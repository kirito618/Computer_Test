#include<stdio.h>
int n,k,k_cnt;
long long maxValue; 
// 差一个点没过 
char input[11];
// 记录每一位后面有没有乘号 
int st[11];

// 将[begin,end]的字符串变成int 
long long to_int(int begin,int end){
	long long res = 0,i;
	for(i=begin;i<=end;i++){
		res = res*10+(input[i]-'0');
	}
	printf("%lld\n",res);
	return res;
}

// 决定每一位的后面能不能加乘号 
void dfs(int cur){
	if(cur==n){
		int i=1,tt;
		long long res = 1;
		if(k_cnt==k){
			tt=1;
			while(i<n){
				if(st[i]==1){
					res = res*to_int(i-tt,i-1);
					tt=1;
				}else{
					tt++;
				}
				i++;
			}
			res = res*to_int(i-tt,i-1);
			maxValue = res>maxValue?res:maxValue;
		}
		return ;
	}
	// cur后面不加乘号 
	dfs(cur+1);
	// cur后面加乘号 
	st[cur]=1;
	k_cnt++;
	dfs(cur+1);
	k_cnt--;
	st[cur]=0;
}

int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",input);
	dfs(1);
	printf("%d\n",maxValue);
	
	return 0;
}
