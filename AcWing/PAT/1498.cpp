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

// ���鼯����ĳ��Ԫ���������ϵı�� 
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
	// ����ÿ���ڵ��Լ���һ����ͨ��ͼ�� 
	for(int i=1;i<=N;i++) p[i] = i;
	
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&a,&b);
		allNodes[a].push_back(b);
		allNodes[b].push_back(a);
		if(find(a)!=find(b)){
			// a��b����һ����ͼ���,��ͼ��-1 
			subG--;
			// ����a��b�ı��Ѿ���������,���԰�a��b�����ļ��Ϻϲ�
			p[find(a)] = find(b);
		}
	}

	if(subG>1){
		// ����1����ͼ,��ô���Ǵ���� 
		cout<<"Error: "<<subG<<" components"<<endl;
		return 0;
	}
	
	
	for(int i=1;i<=N;i++) visited[i] = 0;
	//ֻ��һ����ͼ,��ô������Ϊ��
	// ����ÿ���ڵ����������ڵ㡣
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
