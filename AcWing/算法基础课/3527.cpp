#include<stdio.h>
int first[10][10],second[10][10];
int n;

int check(){
	int i,j,res;
	res = 0;
	// 检查是否为90度旋转
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(first[i][j]!=second[i][j]){
				res = -1;
				break;
			}
		}
		if(res==-1) break;
	}
	if(i>n) return 0;
	else res = 0;
	// 检查是否为90度旋转
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(first[i][j]!=second[j][n-i+1]){
				res = -1;
				break;
			}
		}
		if(res==-1) break;
	}
	if(i>n) return 90;
	else res = 0; 
	// 检查是否为180度旋转
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(second[n-i+1][n-j+1]!=first[i][j]){
				res = -1;
				break;
			}
		}
		if(res==-1) break;
	}
	if(i>n) return 180;
	else res = 0; 
	// 检查是否为270度旋转
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(second[n-j+1][i]!=first[i][j]){
				res = -1;
				break;
			}
		}
		if(res==-1) break;
	}
	if(i>n) return 270;	
	return -1;	
}

int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&first[i][j]);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&second[i][j]);
			
	int res = check();
	printf("%d\n",res);
	
	return 0;
}

/*
3
1 2 3
4 5 6
7 8 9
7 4 1
8 5 2
9 6 3

3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

3
1 2 3
4 5 6
7 8 9
3 6 9
2 5 8
1 4 7
*/
