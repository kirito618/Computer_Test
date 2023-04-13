#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
// ��һ���ύ ֻ��16��! 
// �ڶ����ύ ����֮ǰ����Ŀ����� ��˵5��֮ǰ��û�ֵ��� �Ͳ������� ���sorry
// ������˵�������ʱ����5��֮������sorry  �����Ժ�õ�27�� ����һ�����Ե� 


struct customer{
	int index; 
	int startTime;
	int finishTime;
	int needTime;
};
int N,M,K,Q;
int queueIndexList[20];
queue<customer> allWindow[20];
// ��1��ʼ��� 
customer cus[1001];
// ��ʾ�����Ƿ����ڷ��񣨷���Ļ�����Ǳ������ߵı�ţ� 
int window[20];
int queryList[1000];

bool comp(int i1,int i2){
	int len1 =  allWindow[i1].size();
	int len2 =  allWindow[i2].size();
	if(len1==len2) return i1<i2;
	else return len1<len2;
}



int main(){
	// �Ҷ��Է���Ϊ��λ���� 
	int beginTime = 8*60,endTime = 17*60;
	cin>>N>>M>>K>>Q;
	// ��ʼ�� 
	for(int i=0;i<N;i++){
		window[i] = -1;
		queueIndexList[i] = i;
	}
	for(int i=1;i<=K;i++){
		cin>>cus[i].needTime;
		cus[i].finishTime = -1;
		cus[i].startTime = -1;
		cus[i].index = i;
	}
	//�����ѯ�б� 
	for(int i=0;i<Q;i++) cin>>queryList[i];
	
	int time=beginTime;
	// ������һ����ӵ��˱�� 
	int nextIndex = 1;
	int temp;
	for(time = beginTime;time<endTime;time++){
		//�Ϳ�
		for(int i=0;i<N;i++){
			if(window[i]!=-1){
				temp = window[i];
				if(cus[temp].finishTime==time){
					//������
					allWindow[i].pop();
					// ���ڿ��� 
					window[i] = -1;
				}
			}
		}
		
		// ���
		// �Ȱ���(i) �ٰ���(j)���� 
		for(int i=1;i<=M;i++){
			for(int j=0;j<N;j++){
				// �õ���ǰ���еĳ��� 
				temp = allWindow[j].size();
				// �����ǰ���������� ��ǰ���鳤����С�ڵ�ǰ������
				// ��˵����ÿ������=����ʱ,��һ���������С����̵Ķ��� 
				// ��ô������ĵ�һ���˾�Ӧ�ý����Ŷ��� 
				if(temp<i&&nextIndex<=K){
					allWindow[j].push(cus[nextIndex]);
					nextIndex++;
				}
			}
		} 
		
		// ����ʱ��2 
		for(int i=0;i<N;i++){
			// �õ����б�� 
			if(window[i]==-1){
				//ȡ����� ռ�ô��� 
				window[i] = allWindow[i].front().index;
			}
			if(cus[window[i]].startTime==-1){
				cus[window[i]].startTime = time;
				cus[window[i]].finishTime = time + cus[window[i]].needTime;
			}
		}

	}
	
	int quInd;
	int hh,mm;
	for(int i=0;i<Q;i++){
		quInd = queryList[i];
		if(cus[quInd].startTime==-1) cout<<"Sorry";
		else{
			hh = cus[quInd].finishTime/60;
			mm = cus[quInd].finishTime%60;
			printf("%02d:%02d",hh,mm);
		}
		cout<<endl;
	}
	
	
	return 0;
}
