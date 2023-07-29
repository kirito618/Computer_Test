#include<iostream>
#include<vector>
using namespace std;
int N,M,S,D;
int minDis = 100000000,minMoney = 100000000;
int map[500][500],cost[500][500];
bool visited[500];
// 用于存放最短路径 
//vector<vector<int>> paths;
vector<int> paths;

// 起点，终点，累计价钱，累计距离, 临时容器 
void bfs(int start,int destination,int money,int distance,vector<int> list){
	// 剪枝，已经比之前的路径长了，没必要再继续下去。 
	if(distance>minDis){	
		return;
	}
	
	if(start == destination){
		// 到达了最终点
		if(distance<minDis){
			// 累计距离比之前最短的那条更短
			minDis = distance;
			minMoney = money;
			paths = list;
		}else if(distance == minDis){
			// 距离和之前的最短距离一样，看看谁的价格更少
			if(money < minMoney){
				// 钱更少，更新，这条路径更好
				minDis = distance;
			    minMoney = money;
				paths = list;
			}
		}
		return ;
	}
	
	for(int i=0;i<N;i++){
		if(map[start][i]>0 && (!visited[i])){
			// 两点相通，且目标点为访问过，可以走，接下来进递归
			visited[i] = true;
			list.push_back(i);
			bfs(i,destination,money+cost[start][i],distance+map[start][i],list);
			list.pop_back();
			visited[i] = false;
		}
	}
	
}

int main(){
	int m,n,dis,co,last,cur;
	vector<int> temp;
	cin>>N>>M>>S>>D;
	// 初始化 
	for(int i=0;i<M;i++){
	    for(int j=0;j<M;j++){
		    cost[i][j] = -1;
	    }
	    visited[i] = false;
	}
	visited[S] = true;
	// 输入数据 
	for(int i=0;i<M;i++){
		cin>>m>>n>>dis>>co;
		map[m][n] = map[n][m] = dis;
		cost[m][n] = cost[n][m] = co;
	}
	// 起点就是终点，那么不存在最短路径 
	if(S==D){
		//cout<<S<<" "<<D<<" 0 0"<<endl;
		cout<<S<<" "<<" 0 0"<<endl;
		return 0;
	}
	bfs(S,D,0,0,temp);
	cout<<S;
	temp = paths;
	for(int i=0;i<temp.size();i++){
		cout<<" "<<temp[i];
	}
	cout<<" "<<minDis<<" "<<minMoney<<endl;
	return 0;
}



/*4 5 3 0
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20*/

