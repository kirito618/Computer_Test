#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

// ������¼ÿ��ʽ�ӵķ�0���±�(ָ��)
vector<int> noZero[2];


int main(){
    // ��Ϊ����ÿ��ָ�������1000����ô����ָ������1000+1000
    double xishu[2][1001] = {0},result[2001] = {0},temp;
    int tempK,tempN;
    int countNum = 0;

    // ��������
    for(int i=0;i<2;i++){
        cin>>tempK;
        for(int j=0;j<tempK;j++){
            // ����ָ��
            cin>>tempN;
            // ����ϵ��
            cin>>temp;
            // �������������±�浽��Ӧ����ʽ��vector����ȥ
            noZero[i].push_back(tempN);
            xishu[i][tempN] += temp;
        }
    }


    for(int i=0;i<noZero[0].size();i++){
        for(int j=0;j<noZero[1].size();j++){
            // ������ָ��
            tempN = noZero[0][i] + noZero[1][j];
            // ϵ�����
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



