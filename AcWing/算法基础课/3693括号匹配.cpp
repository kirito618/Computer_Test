#include<stdio.h>
#include<string.h>

char input[100010];
char st[100010];
int top = -1;

char f(char a){
	switch(a){
		case '(':return ')';
		case '[':return ']';
		case '{':return '}';
		case '<':return '>';
	}
}

int main(){
	int i,j,len,res;
	scanf("%s",&input);
	len = strlen(input);
	res = 1;
	for(i=0;i<len;i++){
		
		if(input[i]=='{'||input[i]=='('||input[i]=='['||input[i]=='<'){
			st[++top] = input[i];
		}else{
			if(input[i]==f(st[top])){
				// Æ¥ÅäÔò³öÕ» 
				top--;
			}else{
				res = 0;
				break;
			}
			
		}
	}
	if(top!=-1) res = 0;
	if(res==1) puts("yes");
	else puts("no");
	
	return 0;
} 
