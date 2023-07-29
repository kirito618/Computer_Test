#include<bits/stdc++.h>
using namespace std;

//δ��AC  0�֣����� 

// CmΪÿ��վ���������;NΪվ�ĸ���;Sp���������վ�ı��;M���ж�����· 
int Cm,N,Sp,M;
// ��¼����վ֮��ľ���(ʱ��) 0��pbmc����վ 
int weight[501][501];
int half_full;
// ��¼ÿ��վ�Ѿ������˵����� 
int capacity[501],temp,tempBack,minTime,minNeed,minBack;
vector<int> neighbors[501];
vector<vector<int>> results;
vector<int> tempWay;
vector<int> resultWay; 

void dfs(int cur,int to,int time,int need,int back){
	if(time>minTime) return;
	if(cur==to){
		// �����˸�ȥ�ĵط�
		// ���ǲ������·��
		if(time<minTime){
			results.clear();
			minTime = time;
			minNeed = need;
			resultWay = tempWay;
		}else{
			if(need<minNeed){
				minNeed = need;
				minBack = back;
				resultWay = tempWay;
			}else if(need==minNeed){
				if(back<minBack){
					// ��Ӧ��һ�� �Ǿ�ѡ��������С���Ǹ�
					minBack = back;
					minNeed = need;
					resultWay = tempWay;
				}
			} 
		}
		results.push_back(tempWay);
		return ;
	}
	for(int ne:neighbors[cur]){
		// ����һ�µ�ǰվ�����Լ�������ǰ�����ܹ��ṩ�������г� 
		temp = capacity[ne] - half_full;
		if(temp<=0) temp = 0;
		tempBack = 0;
		if(temp >= need){
			// �Ұ�����֮��  �һ�ʣ�µľ���Ҫ�����ܲ��� 
			tempBack = temp - need;
			temp = need;
		}
		tempWay.push_back(ne);
		capacity[ne] -= temp;
		dfs(ne,to,time+weight[cur][ne],need - temp,back+tempBack);
		capacity[ne] += temp;
		tempWay.pop_back();
	}
}

int main(){
	int from,to,v;
	cin>>Cm>>N>>Sp>>M;
	// ��������״̬����Ҫ�����г��� 
	half_full = Cm/2;
	for(int i=1;i<=N;i++){
		cin>>capacity[i];
	}
	
	for(int i=0;i<M;i++){
		cin>>from>>to>>v;
		neighbors[from].push_back(to);
		weight[from][to] = v;
	}
	
	minTime = 10000000;
	minNeed = 10000000;
	minBack = 10000000;
	tempWay.push_back(0);
	dfs(0,Sp,0,half_full - capacity[Sp],0);
	
	cout<<minNeed<<" ";
	for(int i=0;i<resultWay.size();i++){
		cout<<resultWay[i];
		if(i!=resultWay.size()-1) cout<<"->";
	}
	cout<<" "<<minBack<<endl;
	
	return 0;
}
