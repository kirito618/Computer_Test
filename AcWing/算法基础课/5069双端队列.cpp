#include<stdio.h>
int q[100010],de[100010],t[100010];
int hh,tt,N,K;

int main(){
	int i,j,x,temp,hh1,tt1;
	scanf("%d%d",&N,&K);
	
	for(i=1;i<=N;i++) scanf("%d",&q[i]);
	while(K--){
		tt = 1;
		for(i=1;i<=N;i++) scanf("%d",&de[i]);
		hh1 = 0;
		tt1 = -1;
		for(i=1,j=1;i<=N;i++){
			t[++tt1] = q[i];
			while(hh1<=tt1){
				if(t[tt1]==de[j]){
					tt1--;
					j++;
				}else if(t[hh1]==de[j]){
					hh1++;
					j++;
				}else{
					break;
				}
			}
		}
		if(hh1>tt1) puts("yes");
		else puts("no");
	} 
	
	return 0;
} 
