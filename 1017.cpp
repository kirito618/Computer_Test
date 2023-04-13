#include<bits/stdc++.h>
using namespace std;

struct customer{
	int arriveTime;
	int needTime;
	int completeTime;
};
bool comp(customer a,customer b){
	return a.arriveTime<b.arriveTime;
}

int N,K;
customer c[100001];
int window[100001];

int main(){
	int hh,mm,ss,need,next,Time,j;
	int beginTime = 8*3600;
	int endTime = 17*3600;
	
	char t;
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>hh>>t>>mm>>t>>ss>>need;
		if(need>60){
			need = 60;
		}
		c[i].arriveTime = hh*3600+mm*60+ss;
		c[i].needTime = need * 60;
		c[i].completeTime = 0;
	}
	
	c[N].arriveTime = endTime+1;
	sort(c,c+N,comp);
	// 初始化 
	for(int i=0;i<K;i++) window[i]=-1;
	Time = 0;
	next = 0;
	double waitTime = 0;
	for(Time=beginTime;c[next].arriveTime<=endTime;Time++){
		// 先把当前时刻处理完的顾客送走 
		for(int i=0;i<K;i++){
			if(window[i]>=0){
				j = window[i];
				if(c[j].completeTime==Time){
					window[i]=-1;
				}
			}
		}
		
		for(int i=0;i<K;i++){
			if(window[i]==-1){
				if(c[next].arriveTime<=Time&&c[next].arriveTime<=endTime){
					window[i] = next;
					next++;
				}
			}
		}
		
		for(int i=0;i<K;i++){
			if(window[i]>=0){
				j = window[i];
				if(c[j].completeTime==0){
					waitTime += Time - c[j].arriveTime;
					c[j].completeTime = Time + c[j].needTime;
				}
			}
		}
		
		
	}
	
	printf("%.1f\n",waitTime/next/60);
	return 0;
}
