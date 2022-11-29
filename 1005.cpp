#include<iostream>
#include<string>
using namespace std;

int main(){
    string N,result;
    cin>>N;
    long sum = 0,order = 0;
    for(int i=0;i<N.length();i++){
        sum += N[i] - '0';
    }

    result = to_string(sum);
    for(int i=0;i<result.length();i++){
        if(order!=0){
            cout<<" ";
        }
        switch(result[i]){
            case '0':cout<<"zero";break;
            case '1':cout<<"one";break;
            case '2':cout<<"two";break;
            case '3':cout<<"three";break;
            case '4':cout<<"four";break;
            case '5':cout<<"five";break;
            case '6':cout<<"six";break;
            case '7':cout<<"seven";break;
            case '8':cout<<"eight";break;
            case '9':cout<<"nine";break;
        }
        order++;
    }
    cout<<endl;
    return 0;
}
