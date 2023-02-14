#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 每本书只属于一位作者 
int N,M;//书的总数 以及 请求序列总数 
int digit,ye;
char x;
int count=0;
string ti,au,ke,pu;
struct book{
	int ID;
	string title;
	string author;
	string key;
	string publisher;
	int year;
};
book library[10010];
string search[1010];
int searchIndex[1010];
vector<int> results[1010];
char temp;
string temp_str;
int sort_key,l,r;

void quick_sort(int left,int right,int index){
	if(left>right) return;
	
	l = left;
	r = right;
	sort_key = results[index][left];
	while(l<r){
		while(results[index][r]>sort_key&&l<r){
			r--;
		}
		results[index][l] = results[index][r];
	
		while(results[index][l]<sort_key&&l<r){
			l++;
		}
		results[index][r] = results[index][l];
	}
	results[index][l] = sort_key;
	quick_sort(left,l-1,index);
	quick_sort(l+1,right,index);
}

void find_answer(string word,int column,int index){
	if(column==1){
		//说明按照标题查找
		for(int i=0;i<N;i++){
			if(library[i].title==word){
				results[index].push_back(library[i].ID);
			}
		}
	}else if(column == 2){
		//说明按照作者名字精确查找
		for(int i=0;i<N;i++){
			if(library[i].author==word){
				results[index].push_back(library[i].ID);
			}
		}
	}else if(column == 3){
		//说明按照作关键词查找
		for(int i=0;i<N;i++){
			temp_str = library[i].key;
			l=0;
			r=0;
			count=0;
			while(l<temp_str.length()&&r<word.length()){
				while(temp_str[l]==word[r]&&l<temp_str.length()&&r<word.length()){
					count++;
					l++;
					r++;
				}
				if(count==word.length()){
					//说明包含此关键词！
					results[index].push_back(library[i].ID);
				}else{
					//说明只是局部包含，重新归位 
					count = 0;
					r = 0;
				}
				l++;
			}
		}
	}else if(column == 4){
		//说明按照出版社名字精确查找
		for(int i=0;i<N;i++){
			if(library[i].publisher==word){
				results[index].push_back(library[i].ID);
			}
		}
	}else if(column == 5){
		//说明按照年份精确查找
		for(int i=0;i<N;i++){
			if(to_string(library[i].year)==word){
				results[index].push_back(library[i].ID);
			}
		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>digit;
		getchar();
		getline(cin,ti);
		getline(cin,au);
		getline(cin,ke);
		getline(cin,pu);
		cin>>ye;
		getchar();
		library[i].ID = digit;
		library[i].title = ti;
		library[i].author = au;
		library[i].key = ke;
		library[i].publisher = pu;
		library[i].year = ye;
	}
	cin>>M;
	getchar();
	for(int i=0;i<M;i++){
		cin>>searchIndex[i];
		getchar();
		getchar();
		getline(cin,search[i]);
	}
	
	for(int i=0;i<M;i++){
		cout<<searchIndex[i]<<": "<<search[i]<<endl;
		find_answer(search[i],searchIndex[i],i);
		if(results[i].size()==0){
			cout<<"Not Found"<<endl;
		}else{
			quick_sort(0,results[i].size()-1,i);
			for(int re:results[i]){
				ti = to_string(re);
				count = ti.length();
				if(count<7){
					for(int i=0;i<7-count;i++){
						cout<<"0";
					}
				}
				cout<<re<<endl;
			}
		}
	}
	return 0;
}
