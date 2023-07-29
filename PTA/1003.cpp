#include<iostream>
using namespace std;

/*
    2022/11/27
    无向图
	最短路径
	dfs
*/

int N,M,max_team_num = 0;
int destination,paths=0;
// 地图数组 , 和每个城市拥有的急救队伍数组
int map[500][500],emergency[500];

// 表示到任意一点的最短距离
int shortest[500];


// 深度优先计算最短路径并更新最短路径数组。
void dfs(int cur,int distance,int team_num){
	//若到达当前点的累计距离比上一次到达时记录的最短距离还要大，那么这条路就没
	//必要再走下去了，所以直接返回
	if(distance>shortest[cur])
		return;

	if(cur == destination){
		//若当前位置就是目的地
		if(distance<shortest[cur]){
			//若这次到达目的地的累计距离比之前记录的要短，那就更新并结束函数
			shortest[cur] = distance;
			paths = 1;
			max_team_num = team_num;
		}else{
			//距离和之前某个路径的一样，那就paths+1 即多了一条并列最短的路线
			paths++;
			//若当前累计的队伍数比之前记录的最大值大，那么就更新
		    max_team_num = team_num>max_team_num?team_num:max_team_num;
		}
	}else{
		// 若当前累计的路径长度比上一次到达这个点的距离要短，那么就更新。
		if(distance<shortest[cur]){
			shortest[cur] = distance;
		}
		//当前点还没到最终点
		for(int i=0;i<500;i++){
			//如果当前点与第i个点相邻，就进去递归
			if(map[cur][i]!=-1){
			    dfs(i,distance+map[cur][i],team_num+emergency[i]);
		    }
	    }
    }
}

int main(){23

	int c1,c2;
	int temp1,temp2,l;
	cin>>N>>M>>c1>>c2;

	destination = c2;

	// 距离(地图)二维数组初始化
	for(int i=0;i<500;i++){
		// 先弄个比较大的数当最短距离
		shortest[i] = 1000000000;
		for(int j=0;j<500;j++){
			// 距离为-1 初始化为不可达
			map[i][j] = -1;
		}
	}

	// 输入急救队伍数组
	for(int i=0;i<N;i++){
		cin>>emergency[i];
	}

	for(int i=0;i<M;i++){
		cin>>temp1>>temp2>>l;
		// 记录两点之间的距离(无向图)
		map[temp1][temp2] = map[temp2][temp1] = l;
	}

	// 开始深度优先计算最短路径
	dfs(c1,0,emergency[c1]);
	cout<<paths<<" "<<max_team_num<<endl;

	return 0;
}
