#include<stdio.h>
#include<string.h>
char A[100010],B[100010],res[100010];
int cnt;

// 返回是否a大于b 
int comp(char a[],char b[]){
	int len1 = strlen(a);
	int len2 = strlen(b);
	int i;
	if(len1!=len2) return len1>len2;
	else{
		for(i=0;i<len1;i++){
			if(a[i]>b[i]) return 1;
			else if(a[i]<b[i]) return 0;
		}
	}
	return 1;
} 

void sub(char a[],char b[]){
	//printf("%s\n%s\n",a,b);
	int len1 = strlen(a),len2 = strlen(b);
	int i=len1-1,j=len2-1,cur,jie=0;
	while(i>=0&&j>=0){
		cur = a[i]-b[j]-jie;
		if(cur<0){
			jie = 1;
			cur = (cur+10)%10;
		}else{
			jie = 0;
		}
		res[cnt++] = '0'+cur;
		i--,j--;
	}
	while(i>=0){
		cur = a[i]-'0'-jie;
		if(cur<0){
			jie = 1;
			cur = (cur+10)%10;
		}else{
			jie = 0;
		}
		res[cnt++] = '0'+cur;
		i--;
	}
	while(res[cnt-1]=='0'&&cnt>1) cnt--;
	res[cnt] = '\0';
}

int main(){
	int fu=0,i;
    scanf("%s\n%s",A,B);
    // 取较大的数作为被减数 
    if(comp(A,B)==1) sub(A,B);
    else{
    	fu = 1; 
    	sub(B,A);
	}
	if(fu==1) putchar('-');
	i = strlen(res)-1;
	for(;i>=0;i--) printf("%c",res[i]);
	putchar('\n');
    return 0;
}
