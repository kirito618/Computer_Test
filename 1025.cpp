#include<bits/stdc++.h>
using namespace std; 
int N,K;
struct testee{
	string ID;
	int score;
	int final_rank,location_number,local_rank;
};
testee students[30000];

// ���������� 
bool comp(testee a,testee b){
	return a.score>b.score;
}

// �������������У�������id�Ĵ�С������ 
bool comp2(testee a,testee b){
	if(a.score != b.score) return a.score>b.score;
	else{
		return a.ID<b.ID;
	}
}

int main(){
	int index = 0,j = 0,temp;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>K;
		temp = K;
		while(temp--){
			cin>>students[index].ID>>students[index].score;
			students[index].location_number = i;
			index++;
		}
		sort(students+j,students+index,comp);
		students[j].local_rank = 1;
		for(int y=j+1;y<j+K;y++){
			if(students[y].score == students[y-1].score){
				students[y].local_rank = students[y-1].local_rank;
			}else{
				students[y].local_rank = y-j+1;
			}
		}
		j = index;
	}
	
	sort(students,students+index,comp2);

	students[0].final_rank = 1;
	for(int y=1;y<index;y++){
		if(students[y].score == students[y-1].score){
			students[y].final_rank = students[y-1].final_rank;
		}else{
			students[y].final_rank = y+1;
		}
	}
	cout<<index<<endl; 
	for(int i=0;i<index;i++){
		cout<<students[i].ID<<" "<<students[i].final_rank<<" "<<students[i].location_number<<" "<<students[i].local_rank<<endl;
	}
	
	return 0;
}




























//22��δ��AC 

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//int N,K;
//// ids[i]��Żش�����i�������˺ŵ���� 
//vector<int> ids[101];
//// ������е��˺�id 
//vector<int> all_ids;
//string regs[30000];
//int scores[30000];
//int in_rank[30000];
//int out_rank[30000];
//int problem_index[30000];
//long long right_num[30000];
//long long high_right_num[30000];
//int index=0;
//string buffer;
//long long key,keyIndex,high_key;
//int x,y;
//void quick_sort(int left,int right,bool if_all_sort,int problemId){
//	if(left>right) return ;
//	if(if_all_sort){
//		//���������� 
//		x=left;
//		y=right;
//		key = scores[all_ids[left]];
//		keyIndex = all_ids[left];
//		while(x<y){
//			while(scores[all_ids[y]]<=key&&x<y){
//				y--;
//			}
//			all_ids[x] = all_ids[y];
//			
//			while(scores[all_ids[x]]>=key&&x<y){
//				x++;
//			}
//			all_ids[y] = all_ids[x];
//		}
//		all_ids[x] = keyIndex;
//		quick_sort(left,x-1,true,0);
//		quick_sort(x+1,right,true,0);
//	}else{
//		//�ֲ����� ,Ҫ�õ���������
//		x=left;
//		y=right;
//		
//		key = scores[ids[problemId][left]];
//		keyIndex = ids[problemId][left];
//		while(x<y){
//			while(scores[ids[problemId][y]]<=key&&x<y){
//				y--;
//			}
//			ids[problemId][x] = ids[problemId][y];
//			
//			while(scores[ids[problemId][x]]>=key&&x<y){
//				x++;
//			}
//			ids[problemId][y] = ids[problemId][x];
//		}
//		ids[problemId][x] = keyIndex;
//		quick_sort(left,x-1,false,problemId);
//		quick_sort(x+1,right,false,problemId);
//	}
//}
//
//void quick_sort2(int left,int right){
//	if(left>=right) return;
//	x = left;
//	y = right;
//	key = right_num[all_ids[left]];
//	keyIndex = all_ids[left];
//	high_key = high_right_num[all_ids[left]];
//	while(x<y){
//		//��λ�Ƚϴ���˺žʹ� 
//		while(high_right_num[all_ids[y]]>high_key&&x<y){
//			y--;
//		}
//		
//		while((high_right_num[all_ids[y]]==high_key)&&(right_num[all_ids[y]]>=key)&&x<y){
//			y--;
//		}
//		
//		all_ids[x] = all_ids[y];
//		
//		//��λ�Ƚ�С���˺ž�С 
//		while(high_right_num[all_ids[x]]<high_key&&x<y){
//			x++;
//		}
//		
//		while((high_right_num[all_ids[x]]==high_key)&&right_num[all_ids[x]]<=key&&x<y){
//			x++;
//		}
//		all_ids[y] = all_ids[x];
//	}
//	all_ids[x] = keyIndex;
//	quick_sort2(left,x-1);
//	quick_sort2(x+1,right);
//}
//
//
//
//int main(){
//	string temp;
//	int tempScore;
//	int rank;
//	int count;
//	cin>>N;
//	for(int i=1;i<=N;i++){
//		//i�ʹ���������ı��
//		cin>>K;
//		for(int j=0;j<K;j++){
//			cin>>temp;
//			cin>>tempScore;
//			// ���˺ź���Ž�����ϵ 
//			regs[index] = temp;
//			scores[index] = tempScore;
//			problem_index[index] = i;
//			// �����˺ŵ���Ŵ����Ӧ����������� 
//			ids[i].push_back(index);
//			all_ids.push_back(index); 
//			index++;
//		}
//	}
//	
//	for(int i=0;i<all_ids.size();i++){
//		rank = 1;
//		right_num[all_ids[i]] = 0;
//		buffer = regs[all_ids[i]];
//		for(int j=0;j<5;j++){
//			high_right_num[all_ids[i]] = (buffer[j]-'0') + high_right_num[all_ids[i]]*10;
//		}
//		for(int j=5;j<buffer.length();j++){
//			right_num[all_ids[i]] = (buffer[j]-'0') + right_num[all_ids[i]]*10;
//		}
//	}
//
//	rank=1;
//	count = 1;
//	for(int i=1;i<=N;i++){
//		//ÿ��������оֲ�����
//		quick_sort(0,ids[i].size()-1,false,i);
//		count = 1;
//		rank = 1;
//		in_rank[ids[i][0]] = rank;
//		for(int j=1;j<ids[i].size();j++){
//		 	//��ÿһ��λ����һ����λ��
//			if(scores[ids[i][j]]<scores[ids[i][j-1]]){
//				rank = rank + count;
//				count = 1;
//			}else{
//				count++;
//			}
//			in_rank[ids[i][j]] = rank;
//		 }
//	}
//	
//	rank = 1;
//	// ���ڼ�¼�ظ��������е��м��� 
//	count = 1;
//	// ȫ������ 
//	quick_sort(0,all_ids.size()-1,true,0);
//	
//	index = 0;
//	rank = 1;
//	count = 1;
//	out_rank[all_ids[0]] = rank;
//	for(int i=1;i<all_ids.size();i++){
//		if(scores[all_ids[i]]<scores[all_ids[i-1]]){
//			rank = rank + count;
//			count = 1;
//		}else{
//			count++;
//		}
//		out_rank[all_ids[i]] = rank;
//	}
//	
//	int begin = 0;
//	count = 0;
//	
//	// �˴����������� 
//	for(int i=1;i<all_ids.size();i++){
//		if(scores[all_ids[i]]<scores[all_ids[i-1]]){
//			if(count>0){
//				quick_sort2(begin,begin+count);	
//			}
//			begin = i;
//			count = 0;
//		}else{
//			count++;
//		}
//	}
//	
//	cout<<all_ids.size()<<endl;
//	for(int i=0;i<all_ids.size();i++){
//		cout<<regs[all_ids[i]]<<" "<<out_rank[all_ids[i]]<<" "<<problem_index[all_ids[i]]<<" "<<in_rank[all_ids[i]]<<endl;
//	}
//	
//	return 0;
//}
