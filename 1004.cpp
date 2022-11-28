#include<iostream>
#include<vector>
using namespace std;


/*
    ��AC 2022/11/28 ��
    JAVA����һ�棬AC�ˣ����������c++������дһ��
*/

// ��һ�γ���vector������������Ӧÿ�����ڵ���ӽڵ��б�(��sons[i] ����i�ڵ���ӽڵ��б�)
vector<int> sons[100];
// leaf����������¼ÿһ���Ҷ�ӽڵ�ĸ���
int leaf[100];
int maxLevel = 0;

void dfs(int cur,int level){
    // ����ǰ���(����)�Ѿ�����֮ǰ��¼�������ȣ���ô�͸�����������ֵ
    if(level>maxLevel){
        maxLevel = level;
    }
    if(sons[cur].size()==0){
        // ˵����ǰ�ڵ�û���ӽڵ㣬�Ǹ�Ҷ�ӽڵ㣬��ô��һ���Ҷ�ӽڵ���Ӧ��+1
        leaf[level]++;
        // ��Ϊû���ӽڵ㣬�����˳��ݹ�
        return;
    }

    //�������������ӽڵ��
    for(int i=0;i<sons[cur].size();i++){
        dfs(sons[cur][i],level+1);
    }

}

int main(){
    int N,M,temp,ID,K;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>ID>>K;
        for(int j=0;j<K;j++){
            cin>>temp;
            // ���ӽڵ����ż��뵽���ڵ���ӽڵ��б���ȥ
            sons[ID].push_back(temp);
        }
    }

    // ��Ŀ�涨01�ǵ�һ�����ڵ㣬������int���գ��������ﴫ1��ͬʱ���ǵ�0���
    dfs(1,0);
    // �ݹ���㴦���leaf�����Ѿ������£�����ֻ��Ҫ��0�������������������(��Ϊ��������Ĳ�ѹ��Ҳû�нڵ�)

    //���ԣ�������Ϊ��Ҫ�����һ��������治���пո��������������һ��  Ȼ���� �ո� ֵ�ĸ�ʽ���
    cout<<leaf[0];
    for(int j=1;j<=maxLevel;j++){
        cout<<" "<<leaf[j];
    }
    cout<<endl;

    return 0;
}
