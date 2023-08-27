#include<stdio.h>
#include<string.h>

char A[100010],B[10010];
int res[1000010],cnt;

void multiply(char a[],char b[]){
	int lenA = strlen(a),lenB = strlen(b);
	int i,j,x,y,k,cur,jin,cnt=0;
	for(i=lenA-1;i>=0;i--){
		for(j=lenB-1;j>=0;j--){
			cur = (a[i]-'0')*(b[j]-'0');
			x = lenA-1-i;
			y = lenB-1-j;
			res[x+y] += cur;
			cnt = cnt>(x+y)?cnt:(x+y);
		}
	}
	jin = 0;
	for(i=0;i<=cnt;i++){
		cur = res[i]+jin;
		jin = cur/10;
		res[i] = cur%10;
	}
	if(jin!=0) res[++cnt] = jin;
	while(cnt>=1&&res[cnt]==0) cnt--;
	for(i=cnt;i>=0;i--) printf("%d",res[i]);
	puts("");
}

int main(){
	int lenA,lenB;
	scanf("%s\n%s",A,B);
	lenA = strlen(A),lenB = strlen(B);
	if(lenA>=lenB) multiply(A,B);
	else multiply(B,A);
	
	return 0;
}
