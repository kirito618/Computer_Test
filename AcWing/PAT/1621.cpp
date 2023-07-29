#include<stdio.h>
#include<math.h>

// PAT1128
int N;
int queen[1010];
// 传入列号，判断是否合理 
int check(int j){
	for(int i=0;i<j;i++){
		if(queen[j]==queen[i]||abs(j-i)==abs(queen[j]-queen[i]))
			return 0;
	}
	return 1;
}

int main(){
	int temp,flag;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		flag = 1;
		scanf("%d",&temp);
		for(int j=0;j<temp;j++){
			scanf("%d",&queen[j]);
			if(check(j)==0){
				flag = 0;
			}
		}
		if(flag==0) printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}
