#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
// scores[2000]�����������е�id
vector<int> scores[2001];
vector<int> ranks[2000]; 
// ��¼���е�id���±�
int ids[1000000];
double avg[2000];

int N,M;

void rankMethod(int id){
	int rank,tempIndex;
	// ȡ���±� 
	int index = ids[id];
	// �õ�ƽ��ֵ 
	double avgNum = avg[index];
	// �ȼ���ƽ��ֵ������,��ʼֵΪ1�����б�����ľ�������һ 
	rank = 1;
	for(int temp:scores[2000]){
		//��ÿһ��id�����Ƚ���ƽ��ֵ
		if(avg[ids[temp]]>avgNum) rank++;
	}
	ranks[index].push_back(rank);
	
	// ���������μ���C��M��E������
	for(int i=0;i<3;i++){
		// �Ƚ�������Ϊ1 
		rank = 1; 
		for(int temp:scores[2000]){
		   //ȡ���±�,ȡ����Ӧ�ķ������Ƚϣ������ڵ�ǰid�ķ�����������+1 
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
	    // ����ƽ��ֵ
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
			// id������ 
			cout<<"N/A"<<endl;
		}else{
			// id���ڣ�����id�µ����гɼ��������� 
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
 
