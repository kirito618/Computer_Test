//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int N,l,r,temp_count;
//long long key,minNum = 1000000000000000000;
//long long temp1,temp2;
//string num_str[10000];
//bool visited[10000];
//vector<int> min_indexs;
//
//long long to_num(string num){
//	long long result = 0;
//	for(int i=0;i<num.length();i++){
//		result = result*10 + (num[i]-'0');
//	}
//	return result;
//}
//
//void dfs(string str,int count){
//	if(count==N){
//		temp1 = to_num(str);
//		if(temp1<minNum){
//			minNum = temp1;
//		}
//	}
//	
//	
//	for(int i=0;i<N;i++){
//		if(!visited[i]){
//			visited[i] = true;
//			dfs(str+num_str[i],count+1);
//			visited[i] = false;
//		}
//	}
//}
//
//int main(){
//	string result = "";
//	long long min_begin = 1000000000,temp_long;
//	int max_begin_zero = 0;
//	int zero_count = 0;
//	int min_begin_index;
//	int min_begin_digit = 10;
//	string min_begin_str = "";
//	long long min_begin_num = 1000000000;
//	cin>>N;
//	for(int i=0;i<N;i++){
//		cin>>num_str[i];
//	}
//
//
//	// 找到最小的开头串(先找有开头0的)
//	for(int i=0;i<N;i++){
//		l=0;
//		zero_count=0;
//		while(num_str[i][l]=='0'){
//			zero_count++;
//			l++;
//		}
//		// 这个串的开头0更多，那么它有可能成为最短串的开头 
//		if(zero_count>=max_begin_zero){
//			max_begin_zero = zero_count;
//			min_indexs.push_back(i);
//		}
//	}
//	
//	if(min_indexs.size()==0)
//	{
//		//所有串开头都不是0，选开头数字最小的那个当开头
//		for(int i=0;i<N;i++){
//			l = num_str[i][0] - '0';
//			if(l<min_begin_digit){
//				min_begin_digit = l;
//				min_indexs.clear();
//				min_indexs.push_back(i);
//			}else if(l==min_begin_digit){
//				min_indexs.push_back(i);
//			}
//		}
//	}
//	
//	for(int index_temp:min_indexs){
//		visited[index_temp] = true;
//		dfs(num_str[index_temp],1);
//		visited[index_temp] = false;
//	}
//	cout<<minNum<<endl;
//	return 0;
//}




// 上面是我自己写的递归来解决这个问题，但是只得了24分，超时+超内存 无法通过
// 下面是跟着b站up的思路写的代码
#include<bits/stdc++.h> 
using namespace std;

// 将传入的字符串进行拼接 如传入213 和21  那么拼接为21321 和 21213 这两者字典序最小的是21213
// 所以优先选择21 将21排在213的前面。 
bool cmp(string a,string b){
	string x = a+b;
	string y = b+a;
	return x<y;
}

int main(){
	int N,j;
	string answer = "";
	string s[10000];
	cin>>N;
	for(int i=0;i<N;i++) cin>>s[i];
	
	sort(s,s+N,cmp);
	for(int i=0;i<N;i++) answer+=s[i];
	j=0;
	while(answer[j]=='0') j++;
	if(j==answer.length()){
		//说明这个串全是0
		cout<<0<<endl; 
	}else{
		while(j<answer.length()){
			cout<<answer[j];
			j++;
		}
		cout<<endl;
	}
}
