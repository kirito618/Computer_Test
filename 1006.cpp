#include<iostream>
#include<string>
using namespace std;


/*
    AC  一遍过  2022/11/30
    PAT甲级1006  找出最早登录者和最晚退出者
*/

int main(){
    int M,index;
    string ID_number,Sign_in_time,Sign_out_time;
    string earliest_ID,latest_ID;
    long start_time,end_time;
    long earliest = 10000000000,latest = 0;
    cin>>M;
    for(int i=0;i<M;i++){
        index=1000000;
        start_time=end_time=0;
        cin>>ID_number>>Sign_in_time>>Sign_out_time;
        for(int j=0;j<Sign_in_time.size();j++){
            if(Sign_in_time[j]==':') continue;
            start_time+=(Sign_in_time[j]-'0')*index;
            end_time+=(Sign_out_time[j]-'0')*index;
            index = index/10;
        }
        if(start_time<earliest) {
            earliest = start_time;
            earliest_ID = ID_number;
        }
        if(end_time>latest) {
            latest = end_time;
            latest_ID = ID_number;
        }
    }

    cout<<earliest_ID<<" "<<latest_ID<<endl;
    return 0;
}
