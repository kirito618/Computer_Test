#include<stdio.h>
#include<string.h>

char a[1010],b[1010];
int countA[200],countB[200];

int main(){
	int more=0,less=0;
	scanf("%s\n",a);
	scanf("%s",b);
	int lenA = strlen(a);
	int lenB = strlen(b);
	for(int i=0;i<lenA;i++){
		countA[a[i]]++;
	}
	
	for(int i=0;i<lenB;i++){
		countA[b[i]]--;
	}
	
	for(int i=0;i<200;i++){
		if(countA[i]>0) more+=countA[i];
		else less += countA[i]*(-1);
	}
	
	if(less>0) printf("No %d\n",less);
	else printf("Yes %d\n",more);
	return 0;
}
