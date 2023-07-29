#include<bits/stdc++.h>
using namespace std;
// ���˲��鼯�ĿΣ���������Щ�뷨�����԰���ͨ�ĳ��п���һ����ͨ��ͼ
// ��ôͨ�����鼯���ǿ����ҳ��ж��ٸ���ͼ�������ͼ����һ���ߣ���������Ҫ�޵�ͨ·��
// Ҳ������ͼ��-1
int N,M,K;
int p[1010];
vector<int> graph[1010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int a,b,c,subG;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=0;i<K;i++){
		// �������c����ռ��? ��ʣ�¼�����ͨ��ͼ�� 
		scanf("%d",&c);
		subG = N-1;
		for(int j=1;j<=N;j++) p[j] = j;
		for(int j=1;j<=N;j++){
			if(j==c) continue;
			for(int k:graph[j]){
				if(k==c) continue;
				if(find(k)!=find(j)){
					// ���ߺϲ� 
					p[find(k)] = find(j);
					// ��ͨͼ����-1 
					subG--;
				}
			}
		}
		printf("%d\n",subG-1);
	}
	
	return 0;
} 
