#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

// 用来记录每个式子的非0项下标(指数)
vector<int> noZero[2];


int main(){
    // 因为他这每个指数最大都是1000，那么最大的指数就是1000+1000
    double xishu[2][1001] = {0},result[2001] = {0},temp;
    int tempK,tempN;
    int countNum = 0;

    // 输入数据
    for(int i=0;i<2;i++){
        cin>>tempK;
        for(int j=0;j<tempK;j++){
            // 输入指数
            cin>>tempN;
            // 输入系数
            cin>>temp;
            // 把这个非零项的下标存到对应多项式的vector容器去
            noZero[i].push_back(tempN);
            xishu[i][tempN] += temp;
        }
    }


    for(int i=0;i<noZero[0].size();i++){
        for(int j=0;j<noZero[1].size();j++){
            // 计算新指数
            tempN = noZero[0][i] + noZero[1][j];
            // 系数相乘
            result[tempN] += xishu[0][noZero[0][i]] * xishu[1][noZero[1][j]];
        }
    }
    for(int i=0;i<2001;i++){
        if(result[i]!=0)
        countNum++;
    }
    cout<<countNum;

    for(int i=2000;i>=0;i--){
        if(result[i]!=0){
            printf(" %d %.1f",i,result[i]);
        }
    }
    cout<<endl;

    return 0;
}



