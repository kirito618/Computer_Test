#include<iostream>
#include<string>
#include<map>
using namespace std;

string input;
char op_st[100010];
int  num_st[100010];
int top_n = 0,top_o = 0;
map<char,int> priority;

void init(){
	priority['('] = 0;
	priority['+'] = 1;
	priority['-'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;
}

int getNum(string str){
	int result = 0;
	for(int i=0;i<str.length();i++){
		result = result*10 + (str[i] - '0');
	}
	return result;
}

int getResult(int a,int b,char op){
	int result = 0;
	if(op=='+') result = a+b;
	else if(op=='-') result = a-b;
	else if(op=='*') result = a*b;
	else if(op=='/') result = a/b;
//	cout<<a<<op<<b<<"="<<result<<endl;
	return result;
}

int main(){
	init();
	int temp;
	int b,a,c;
	char tt;
	cin>>input;
	for(int i=0;i<input.length();i++){
		temp = 0; //记录是否是两位及以上的数字 
		if(input[i]>='0'&&input[i]<='9'){
			string num = "";
			c = i;
			// 数字入数字栈 
			while(input[c]>='0'&&input[c]<='9'){
				num += input[c];
				temp++;
				c++;
			}
			i+=temp-1;
			num_st[top_n++] = getNum(num);
		}else{
			if(input[i]=='(') op_st[top_o++] = input[i];
			else if(input[i]==')'){
				while(top_o>0&&op_st[top_o-1]!='('){
					tt = op_st[--top_o];
					b = num_st[--top_n];
					a = num_st[--top_n];
					num_st[top_n++] = getResult(a,b,tt);
				}
				if(op_st[top_o-1]=='(')
					top_o--;//弹出左括号 
			}
			else{
				while(priority[op_st[top_o-1]]>=priority[input[i]]){
					tt = op_st[--top_o];
					b = num_st[--top_n];
					a = num_st[--top_n];
					num_st[top_n++] = getResult(a,b,tt);
				}
				op_st[top_o++] = input[i];
			}
		}
	}
	
	while(top_o!=0){
		tt = op_st[--top_o];
		b = num_st[--top_n];
		a = num_st[--top_n];
		num_st[top_n++] = getResult(a,b,tt);
	}
	
	cout<<num_st[top_n-1]<<endl;
	return 0;
}
