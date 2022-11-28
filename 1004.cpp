#include<iostream>
#include<vector>
using namespace std;


/*
    已AC 2022/11/28 晚
    JAVA交了一版，AC了，这次试着用c++来重新写一下
*/

// 第一次尝试vector，这里用来对应每个根节点的子节点列表(即sons[i] 就是i节点的子节点列表)
vector<int> sons[100];
// leaf数组用来记录每一层的叶子节点的个数
int leaf[100];
int maxLevel = 0;

void dfs(int cur,int level){
    // 若当前深度(层数)已经大于之前记录的最大深度，那么就更新最大层数的值
    if(level>maxLevel){
        maxLevel = level;
    }
    if(sons[cur].size()==0){
        // 说明当前节点没有子节点，是个叶子节点，那么这一层的叶子节点数应该+1
        leaf[level]++;
        // 因为没有子节点，所以退出递归
        return;
    }

    //接下来处理有子节点的
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
            // 将子节点的序号加入到根节点的子节点列表中去
            sons[ID].push_back(temp);
        }
    }

    // 题目规定01是第一个根节点，我们用int接收，所以这里传1，同时它是第0层的
    dfs(1,0);
    // 递归计算处理后，leaf数组已经被更新，我们只需要从0到最大层数进行输出即可(因为再往后面的层压根也没有节点)

    //啊对，这里因为他要求最后一个结果后面不能有空格，所以我们先输出一个  然后按照 空格 值的格式输出
    cout<<leaf[0];
    for(int j=1;j<=maxLevel;j++){
        cout<<" "<<leaf[j];
    }
    cout<<endl;

    return 0;
}
