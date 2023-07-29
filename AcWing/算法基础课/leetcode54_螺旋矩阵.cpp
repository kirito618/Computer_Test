#include<iostream>
#include<vector>
using namespace std;

int m,n;
int cnt;
int arr[10][10];
vector<int> result;

void method(int x,int y){
	int top,bot,left,right,i,j;
	top = 0;bot = m-1;left = 0;right = n-1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			arr[i][j] = (++cnt);
		}
	}
	
	cnt = 0;
	while(cnt<n*m){
		i = top;
		j = left;
		if(top==left&&left==bot&&left==right){
			result.push_back(arr[i][j]);
			cnt++;
			break;
		}
		while(j<right&&cnt<n*m){
			result.push_back(arr[i][j]);
			cnt++;
			j++;
		}
		while(i<bot&&cnt<n*m){
			result.push_back(arr[i][j]);
			cnt++;
			i++;
		}
		while(j>left&&cnt<n*m){
			result.push_back(arr[i][j]);
			cnt++;
			j--;
		}
		while(i>top&&cnt<n*m){
			result.push_back(arr[i][j]);
			cnt++;
			i--;
		}
		left++;bot--;
		top++;right--;
	}
	
	printf("[%d",result[0]);
	for(int i=1;i<cnt;i++){
		printf(",%d",result[i]);
	}
	printf("]\n");
}

int main(){
	scanf("%d%d",&m,&n);
	method(m,n);
	
	return 0;
}
