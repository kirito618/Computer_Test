#include<iostream>
#include<vector>
using namespace std;


/*
    ��AC��2022/12/01
*/


// ֻ�ǵ����ĵݹ����Ļ����ᵼ��ָ�������ظ����㣬�����ύʱ���ֳ�ʱ����
// ����֦�Ż�����һ����ԭ��ֵ���ڶ��������ͣ������������͵����г��� ���ĸ���ʶ�Ƿ��޸Ĺ�
vector<int> database[10000];
int maxSum = 0;
int maxBeginIndex = 9999;
int K;


// ����ֵ���Ե�ǰλ��Ϊ��ʼ������ܹ��ҵ�������
int method(int cur){

    // ���һ���ˣ��������;������Լ�,���г���Ϊ1
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

    // ��֦����
    if(database[cur][3]){
        return database[cur][1];
    }

    int tempSum = database[cur][0] + method(cur+1);
    int tempMax = database[cur][0];
    if(tempSum > tempMax){
        // ���г���+1
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
        // ��ʼֵû�б��ı䣬��˵��������е�����ֵ���Ǹ��ģ�����ĿҪ������������
        cout<<0<<" "<<database[0][0]<<" "<<database[K-1][0]<<endl;
    }else{
        int endIndex = maxBeginIndex + database[maxBeginIndex][2]-1;
        int beginNum = database[maxBeginIndex][0];
        int endNum = database[endIndex][0];
        cout<<maxSum<<" "<<beginNum<<" "<<endNum<<endl;
    }


    return 0;
}
