#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;
string s;
int N;

// 用于判断此时的取值是否满足条件
// 即任意一个长度为mid的字串都是独一无二的 
bool valid(int mid){
	// 创建一个哈希表  存入所有长度为mid的子串 
	unordered_set<string> database;
	for(int i=0;i<=N-mid+1;i++){
		// 截取长度为mid的字串 
		string son = s.substr(i,mid);
		if(database.count(son)){
			// 哈希表里已经有了  说明是重复的子串
			return false;
		}
		database.insert(son);
	}
	// 上面没有返回  说明没有重复的长度为mid的子串 
	return true;
	
}

int main(){
	int l,r,mid;
	cin>>N>>s;
	l = 0;
	r = N;
	
	// 二分查找 
	while(l<r){
		// 这里是二进制右移一位  相当于除以2 
		mid = (l+r)>>1;
		if(valid(mid)){
			// 这个值成立 那么答案就是这个值 或者在这个值的左侧
			// 因为如果说这个值能成立  那么所有大于mid的子串也都是独一无二的
			// 所以这个值就是条件成立的一个值 而真正的answer<=mid 
			r = mid; 
		}else{
			l = mid + 1;
		}
	}
	
	// 退出循环时l==r 故输出谁都一样 
	cout<<r<<endl;
	
	return 0;
}
