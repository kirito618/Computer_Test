#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
vector<char> chooseList[1];

int main(){
    double W,T,L,max_odd = 0;
    double result = 1;
    char chosen;
        for(int i=0;i<3;i++){
        cin>>W>>T>>L;
        max_odd = W;
        chosen = 'W';
        if(max_odd<T){
            max_odd = T;
            chosen = 'T';
        }

        if(max_odd<L){
            max_odd = L;
            chosen = 'L';
        }
        result = result*max_odd;
        chooseList[0].push_back(chosen);
      }

    for(int i=0;i<chooseList[0].size();i++)
        cout<<chooseList[0][i]<<' ';

    result = (result*0.65 - 1)*2;
    printf("%.2f\n",result);
    return 0;
}
