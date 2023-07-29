#include<iostream>
using namespace std;

int main(){
    int N;
    int sum = 0;
    int temp,now;
    cin>>N;
    cin>>temp;
    sum += temp * 6 + 5;
    for(int i=1;i<N;i++){
        cin>>now;
        if(now>temp){
            sum += (now - temp)*6;
        }else if(now<temp){
            // 下楼
            sum += (temp - now)*4;
        }
        sum += 5;
        // 将当前层改成上一层
        temp = now;
    }

    cout<<sum<<endl;
    return 0;
}
