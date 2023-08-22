#include<stdio.h>

int two[100];

int main(){
	int T,i,num,res;
	two[0] = 1;
	for(i=1;i<=32;i++) two[i] = two[i-1]*2;
	scanf("%d",&T);
	while(T--){
		res = 0;
		scanf("%d",&num);
		for(i=1;i<=32;i++){
			if(num<two[i]){
				break;
			}else if(num==two[i]){
				res = 1;
				break;
			}
		}
		if(res==0) puts("NO");
		else puts("YES");
	}
	return 0;
}
