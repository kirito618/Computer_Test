#include<iostream>
#include<string>
using namespace std;
int char_map[1000];

int main(){
	string words,delete_word;
	string result = "";
	int index;
	bool flag;
	getline(cin,words);
	getline(cin,delete_word);
	for(int i=0;i<delete_word.length();i++){
		index = (int)delete_word[i];
		char_map[index] = 1;
	}
	for(int i=0;i<words.length();i++){
		if(char_map[words[i]]!=1){
			result += words[i];
		}
	}
	cout<<result<<endl;
	return 0;
}
