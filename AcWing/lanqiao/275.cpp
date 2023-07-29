#include<bits/stdc++.h>

using namespace std;

// δAC 
int m,n;
int w[52][52];
// ��¼��һ�ε� i~j ����ֽ�������ø� 
int dp1[52][52];
// ��¼�ڶ��ε� i~j ����ֽ�������ø� 
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
	
	// ����������·����ע���� 
	x = m;
	y = n;
	while(x!=1&&y!=1){
		w[x][y]=0;
		if(dp1[x-1][y]>dp1[x][y-1]){
			// ˵���Ǵ�����ĵ��߹�����
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
