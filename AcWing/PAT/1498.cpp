#include<bits/stdc++.h>

using namespace std;

vector<int> allNodes[10010];
vector<int> results;
int N,subG;
int visited[10010];
int p[10010];
int maxLevel = -1;

void findSubG(int cur){
	if(visited[cur]==1) return ;
	visited[cur] = 1;
	for(int son:allNodes[cur])
		findSubG(son);
}

// 并查集查找某个元素所属集合的编号 
int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int dfs(int cur,int father){
	int result=-1,temp;
	for(int son:allNodes[cur]){
		if(father==son) continue;
		result = max(result,dfs(son,cur)+1);
	}
	return result;
}

int main(){
	int a,b;
	scanf("%d",&N);
	//	subG = 0;
	subG = N;
	// 先让每个节点自己当一个连通子图。 
	for(int i=1;i<=N;i++) p[i] = i;
	
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&a,&b);
		allNodes[a].push_back(b);
		allNodes[b].push_back(a);
		if(find(a)!=find(b)){
			// a和b不是一个子图里的,子图数-1 
			subG--;
			// 由于a和b的边已经被考虑了,所以把a和b所属的集合合并
			p[find(a)] = find(b);
		}
	}

	if(subG>1){
		// 超过1个子图,那么就是错误的 
		cout<<"Error: "<<subG<<" components"<<endl;
		return 0;
	}
	
	
	for(int i=1;i<=N;i++) visited[i] = 0;
	//只有一个子图,那么可以视为树
	// 就让每个节点轮流当根节点。
	for(int i=1;i<=N;i++){
		int level = dfs(i,0);
		if(level>maxLevel){
			maxLevel = level;
			results.clear();
			results.push_back(i);
		}else if(level==maxLevel){
			results.push_back(i);
		}
	}
	for(int r:results) printf("%d\n",r);
	return 0;
}
