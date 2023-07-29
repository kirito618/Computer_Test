#include<bits/stdc++.h>

using namespace std;

// 未AC 
int m,n;
int w[52][52];
// 记录第一次的 i~j 传递纸条的最大好感 
int dp1[52][52];
// 记录第二次的 i~j 传递纸条的最大好感 
int dp2[52][52];

int main(){
	int x,y;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>w[i][j];
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1])+w[i][j];
		}
	}
	
	// 将最大的这条路径标注出来 
	x = m;
	y = n;
	while(x!=1&&y!=1){
		w[x][y]=0;
		if(dp1[x-1][y]>dp1[x][y-1]){
			// 说明是从上面的点走过来的
			x--;
		}else{
			y--;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			x = dp2[i-1][j];
			y = dp2[i][j-1];
			dp2[i][j] = max(x,y)+w[i][j];
		}
	}
	
	cout<<dp2[m][n]<<endl;
	cout<<dp1[m][n]+dp2[m][n]<<endl;
	return 0;
}
