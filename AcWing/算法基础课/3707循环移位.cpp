#include<stdio.h>
#include<string.h>
char A[110],B[110];

int check(){
	int len1 = strlen(A);
	int len2 = strlen(B);
	if(len1>len2) return 0;
	int t = len2;
	int i=0,j;
	while(t--){
		j = 0;
		while(j<len1&&A[j]==B[(i+j)%len2]){
			j++;
		}
		if(j==len1) return 1;
		i = (i+1)%len2;
	}
	return 0;
}

int main(){
	int res;
	while(scanf("%s %s",A,B)!=EOF){
		res = check();
		if(res==1) puts("yes");
		else puts("no");
	}
	
	return 0;
}
