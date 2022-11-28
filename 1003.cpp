#include<iostream>
using namespace std;

/*
    2022/11/27
    ����ͼ
	���·��
	dfs
*/

int N,M,max_team_num = 0;
int destination,paths=0;
// ��ͼ���� , ��ÿ������ӵ�еļ��ȶ�������
int map[500][500],emergency[500];

// ��ʾ������һ�����̾���
int shortest[500];


// ������ȼ������·�����������·�����顣
void dfs(int cur,int distance,int team_num){
	//�����ﵱǰ����ۼƾ������һ�ε���ʱ��¼����̾��뻹Ҫ����ô����·��û
	//��Ҫ������ȥ�ˣ�����ֱ�ӷ���
	if(distance>shortest[cur])
		return;

	if(cur == destination){
		//����ǰλ�þ���Ŀ�ĵ�
		if(distance<shortest[cur]){
			//����ε���Ŀ�ĵص��ۼƾ����֮ǰ��¼��Ҫ�̣��Ǿ͸��²���������
			shortest[cur] = distance;
			paths = 1;
			max_team_num = team_num;
		}else{
			//�����֮ǰĳ��·����һ�����Ǿ�paths+1 ������һ��������̵�·��
			paths++;
			//����ǰ�ۼƵĶ�������֮ǰ��¼�����ֵ����ô�͸���
		    max_team_num = team_num>max_team_num?team_num:max_team_num;
		}
	}else{
		// ����ǰ�ۼƵ�·�����ȱ���һ�ε��������ľ���Ҫ�̣���ô�͸��¡�
		if(distance<shortest[cur]){
			shortest[cur] = distance;
		}
		//��ǰ�㻹û�����յ�
		for(int i=0;i<500;i++){
			//�����ǰ�����i�������ڣ��ͽ�ȥ�ݹ�
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

	// ����(��ͼ)��ά�����ʼ��
	for(int i=0;i<500;i++){
		// ��Ū���Ƚϴ��������̾���
		shortest[i] = 1000000000;
		for(int j=0;j<500;j++){
			// ����Ϊ-1 ��ʼ��Ϊ���ɴ�
			map[i][j] = -1;
		}
	}

	// ���뼱�ȶ�������
	for(int i=0;i<N;i++){
		cin>>emergency[i];
	}

	for(int i=0;i<M;i++){
		cin>>temp1>>temp2>>l;
		// ��¼����֮��ľ���(����ͼ)
		map[temp1][temp2] = map[temp2][temp1] = l;
	}

	// ��ʼ������ȼ������·��
	dfs(c1,0,emergency[c1]);
	cout<<paths<<" "<<max_team_num<<endl;

	return 0;
}
