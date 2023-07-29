#include<iostream>
#include<algorithm>
using namespace std;
// 已经AC，感觉和动态规划关系不是很大
// 就是维护一个 左侧区间最大值 右侧区间最小值
// 维护过程是递推，leftMax[i] = max(leftMax[i-1],num[i])
// rightMin[i] = min(right[i+1],num[i+1])

int N;
long long num[100010];
long long leftMax[100010],rightMin[100010];
long long result[100010];
int cnt;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num[i];
	}	
	leftMax[0] = -1;// 表示左边没有数 
	for(int i=1;i<N;i++){
		leftMax[i] = max(leftMax[i-1],num[i-1]);
	}
	rightMin[N] = 1000000001; // 表示右边没有数
	num[N] = 1000000001;
	for(int i=N-1;i>=0;i--){
		rightMin[i] = min(rightMin[i+1],num[i+1]);
		if(rightMin[i]>num[i]&&leftMax[i]<num[i]){
			// 合理 
			result[cnt++] = num[i]; 
		}
	}
	cout<<cnt<<endl;
	reverse(result,result+cnt);
	if(cnt!=0)
		cout<<result[0];
	for(int i=1;i<cnt;i++){
		cout<<" "<<result[i];
	}
	cout<<endl;
	return 0;
}
