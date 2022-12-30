#include<iostream>
#include<vector>
using namespace std;
vector<int> map[1001];
// lost 表示的是被占领的那个点 
int N,M,K,lost;
bool visited[1000]; 

// 判断从from到to是否可达 
void dfs(int cur){
	//把当前点置为已访问 
	visited[cur] = true;
	
	for(int i:map[cur]){
		//对当前点所相邻的所有未访问且未被占领的点都进行深度优先遍历
		if((!visited[i])&&(i!=lost)){
		    dfs(i);
	    }
	}
	
}

int main(){
	int i,j,k,l;
	int num;
	
	cin>>N>>M>>K;
	// 图的建立 
	for(i = 0;i < M;i++){
		cin>>j>>l;
		// 无向图，表示二者连通了 
		map[j].push_back(l);
		map[l].push_back(j);
	}
	
	// 接下来输入K个可能被占领的点，每个点都进行处理
	// 计算连通子图的个数，然后子图个数-1就是我们要修补的路的个数
	
	for(j=0;j<K;j++){
		// 连通子图个数置为0 
		num = 0;
		cin>>lost;
		for(i=1;i<=N;i++)visited[i] = false;
		for(i=1;i<=N;i++){
			if((i!=lost) && (!visited[i])){
				//当前点没被访问过，且没被占领，那么就可以是一个连通子图的开始点
				num++;
				//把从这个节点出发能到达的所有点全部置为已访问 
				dfs(i);
			}
		}
		// 记录下分别需要补的路数
		map[1000].push_back(num-1);
	}

	for(int result:map[1000]){
		cout<<result<<endl;
	}
	return 0;
}
