#include<stdio.h>
#include<string.h>

char input[90];
int main(){
	int n1,n2,n3,a,b;
	scanf("%s",input);
	// ÕÒ³ön1¡¢n2¡¢n3
	int N = strlen(input);
	int fi = 0;
	// ÕÒ³ön2 
	for(int x=3;x<=N;x++){
		for(int k=1;k<=x;k++){
			if(N-x-2*k+2==0){
				fi = fi>k?fi:k; 
			}
		}
	}
	n1 = fi;
	n3 = fi;
	n2 = N-n1*2+2;
	char space = ' ';
	for(int i=0;i<n1-1;i++){
		printf("%c",input[i]);
		for(int l = 0;l<n2-2;l++) printf("%c",space);
		fi = n1+n2+n3-i-3;
		printf("%c\n",input[fi]);
	}
	for(int i=0;i<n2;i++){
		printf("%c",input[n1-1+i]);
	}
	printf("\n");
	return 0;
} 
