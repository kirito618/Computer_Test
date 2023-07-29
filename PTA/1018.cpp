#include<bits/stdc++.h>
using namespace std;

//未能AC  0分！！！ 

// Cm为每个站的最大容量;N为站的个数;Sp是有问题的站的编号;M是有多少条路 
int Cm,N,Sp,M;
// 记录两个站之间的距离(时间) 0是pbmc服务站 
int weight[501][501];
int half_full;
// 记录每个站已经分配了的容量 
int capacity[501],temp,tempBack,minTime,minNeed,minBack;
vector<int> neighbors[501];
vector<vector<int>> results;
vector<int> tempWay;
vector<int> resultWay; 

void dfs(int cur,int to,int time,int need,int back){
	if(time>minTime) return;
	if(cur==to){
		// 到达了该去的地方
		// 看是不是最短路径
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
					// 供应量一样 那就选带回量最小的那个
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
		// 计算一下当前站点在自己完美的前提下能够提供多少自行车 
		temp = capacity[ne] - half_full;
		if(temp<=0) temp = 0;
		tempBack = 0;
		if(temp >= need){
			// 我帮助你之后  我还剩下的就是要带回总部的 
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
	// 计算完美状态所需要的自行车数 
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
