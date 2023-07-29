#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
// scores[2000]里面存的是所有的id
vector<int> scores[2001];
vector<int> ranks[2000]; 
// 记录所有的id的下标
int ids[1000000];
double avg[2000];

int N,M;

void rankMethod(int id){
	int rank,tempIndex;
	// 取出下标 
	int index = ids[id];
	// 拿到平均值 
	double avgNum = avg[index];
	// 先计算平均值的排名,初始值为1，若有比他大的就排名加一 
	rank = 1;
	for(int temp:scores[2000]){
		//对每一个id，都比较其平均值
		if(avg[ids[temp]]>avgNum) rank++;
	}
	ranks[index].push_back(rank);
	
	// 接下来依次计算C、M、E的排名
	for(int i=0;i<3;i++){
		// 先将排名置为1 
		rank = 1; 
		for(int temp:scores[2000]){
		   //取出下标,取出对应的分数做比较，若大于当前id的分数，则排名+1 
		   tempIndex = ids[temp];
		   if(scores[tempIndex][i]>scores[index][i]) rank++;
	   }
	   ranks[index].push_back(rank);
	}
}

int main(){
	int Cs,Math,Eng;
	int tempId,tempIndex;
	cin>>N>>M;
	for(int i=0;i<1000000;i++) ids[i] = -1;
	char result[4];
	result[0] = 'A';
	result[1] = 'C';
	result[2] = 'M';
	result[3] = 'E';
	for(int i=0;i<N;i++){
		//scanf("%d",&tempId);
		cin>>tempId;
	    //scanf("%d %d %d",&Cs,&Math,&Eng);
	    cin>>Cs>>Math>>Eng;
	    // 计算平均值
	    avg[i] = (Cs+Math+Eng)/3.0;
	    scores[i].push_back(Cs);
	    scores[i].push_back(Math);
	    scores[i].push_back(Eng);
	    ids[tempId] = i;
	    scores[2000].push_back(tempId);
	}
	
	for(int i=0;i<M;i++){
		cin>>tempId;
		tempIndex = ids[tempId];
		if(tempIndex == -1){
			// id不存在 
			cout<<"N/A"<<endl;
		}else{
			// id存在，将此id下的所有成绩计算排名 
			rankMethod(tempId);
			int min = 0;
			for(int j=1;j<4;j++){
				if(ranks[tempIndex][j] < ranks[tempIndex][min]){
					min = j;
				}
			}
			cout<<ranks[tempIndex][min]<<" "<<result[min]<<endl;
		}
	}	
	return 0;
}
 
