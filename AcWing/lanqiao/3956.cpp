#include<iostream>
using namespace std;

// 已经AC 
long long n;
long long a[100000];
// 记录以下标i为结尾,以0为开头的区间和 
long long sum[100000];
// 记录以下标i为结尾的闭区间内有多少个前缀和为 S/3的 
long long cnt[100000];
int main(){
	long long x,result = 0;
	long long first,second;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
			x = sum[i-1];
		}else{
			x = 0;
		}
		sum[i] = x + a[i];
	}
	
	if(sum[n-1]%3!=0||n<3){
		// 不能划分成三个拥有相同和的子区间 无解
		cout<<0<<endl;
		return 0; 
	}
	
	cnt[0] = sum[0]==sum[n-1]/3?1:0;
	
	for(int i=1;i<n;i++){
		if(sum[i]==sum[n-1]/3){
			// 说明以i为结尾的闭区间内的和为 S/3
			// 计数器加1
			cnt[i] = cnt[i-1]+1; 
		}else{
			cnt[i] = cnt[i-1];
		}
	}
	
	for(int i=1;i<n-1;i++){
		if(sum[i]==2*sum[n-1]/3){
			//说明此端点的左侧区间和为 2/3*S
			result += cnt[i-1];
		}
	}
	
	cout<<result<<endl;
	return 0;
}
