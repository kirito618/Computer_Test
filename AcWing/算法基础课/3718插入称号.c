#include<stdio.h>
int n,k,k_cnt;
long long maxValue; 
// ��һ����û�� 
char input[11];
// ��¼ÿһλ������û�г˺� 
int st[11];

// ��[begin,end]���ַ������int 
long long to_int(int begin,int end){
	long long res = 0,i;
	for(i=begin;i<=end;i++){
		res = res*10+(input[i]-'0');
	}
	printf("%lld\n",res);
	return res;
}

// ����ÿһλ�ĺ����ܲ��ܼӳ˺� 
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
	// cur���治�ӳ˺� 
	dfs(cur+1);
	// cur����ӳ˺� 
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
