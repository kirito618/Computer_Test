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
//	// �ҵ���С�Ŀ�ͷ��(�����п�ͷ0��)
//	for(int i=0;i<N;i++){
//		l=0;
//		zero_count=0;
//		while(num_str[i][l]=='0'){
//			zero_count++;
//			l++;
//		}
//		// ������Ŀ�ͷ0���࣬��ô���п��ܳ�Ϊ��̴��Ŀ�ͷ 
//		if(zero_count>=max_begin_zero){
//			max_begin_zero = zero_count;
//			min_indexs.push_back(i);
//		}
//	}
//	
//	if(min_indexs.size()==0)
//	{
//		//���д���ͷ������0��ѡ��ͷ������С���Ǹ�����ͷ
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




// ���������Լ�д�ĵݹ������������⣬����ֻ����24�֣���ʱ+���ڴ� �޷�ͨ��
// �����Ǹ���bվup��˼·д�Ĵ���
#include<bits/stdc++.h> 
using namespace std;

// ��������ַ�������ƴ�� �紫��213 ��21  ��ôƴ��Ϊ21321 �� 21213 �������ֵ�����С����21213
// ��������ѡ��21 ��21����213��ǰ�档 
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
		//˵�������ȫ��0
		cout<<0<<endl; 
	}else{
		while(j<answer.length()){
			cout<<answer[j];
			j++;
		}
		cout<<endl;
	}
}
