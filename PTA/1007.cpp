#include<iostream>
#include<vector>
using namespace std;


/*
    已AC，2022/12/01
*/


// 只是单纯的递归计算的话，会导致指数级的重复计算，最终提交时出现超时错误。
// 做剪枝优化，第一个是原数值，第二个是最大和，第三个是最大和的序列长度 第四个标识是否被修改过
vector<int> database[10000];
int maxSum = 0;
int maxBeginIndex = 9999;
int K;


// 返回值是以当前位作为开始，向后能够找到的最大和
int method(int cur){

    // 最后一项了，所以最大和就是他自己,序列长度为1
    if(cur==K-1){
        if(database[cur][0]>maxSum){
            maxBeginIndex = cur;
            maxSum = database[cur][0];
            database[cur][1] = maxSum;
            database[cur][2] = 1;
            database[cur][3] = true;
        }
        return database[cur][0];
    }else if(cur>K-1){
        return 0;
    }

    // 剪枝处理
    if(database[cur][3]){
        return database[cur][1];
    }

    int tempSum = database[cur][0] + method(cur+1);
    int tempMax = database[cur][0];
    if(tempSum > tempMax){
        // 序列长度+1
        database[cur][2] = database[cur+1][2] + 1;
        database[cur][3] = true;
        tempMax = tempSum;
    }

    if(tempMax >= maxSum){
        maxSum = tempMax;
        maxBeginIndex = cur<maxBeginIndex?cur:maxBeginIndex;
    }

    return tempMax;
}


int main(){
    int temp;
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>temp;
        database[i].push_back(temp);
        database[i].push_back(temp);
        database[i].push_back(1);
        database[i].push_back(false);
    }

    for(int i=0;i<K;i++){
        method(i);
    }
    if(maxBeginIndex == 9999){
        // 初始值没有被改变，那说明这个序列的所有值都是负的，按题目要求进行输出即可
        cout<<0<<" "<<database[0][0]<<" "<<database[K-1][0]<<endl;
    }else{
        int endIndex = maxBeginIndex + database[maxBeginIndex][2]-1;
        int beginNum = database[maxBeginIndex][0];
        int endNum = database[endIndex][0];
        cout<<maxSum<<" "<<beginNum<<" "<<endNum<<endl;
    }


    return 0;
}
