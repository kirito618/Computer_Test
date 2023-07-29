#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
// 第一次提交 只有16分! 
// 第二次提交 发现之前对题目有误解 是说5点之前还没轮到的 就不服务了 输出sorry
// 而不是说服务完的时间在5点之后的输出sorry  改了以后得到27分 仅差一个测试点 


struct customer{
	int index; 
	int startTime;
	int finishTime;
	int needTime;
};
int N,M,K,Q;
int queueIndexList[20];
queue<customer> allWindow[20];
// 从1开始编号 
customer cus[1001];
// 表示窗口是否正在服务（服务的话存的是被服务者的编号） 
int window[20];
int queryList[1000];

bool comp(int i1,int i2){
	int len1 =  allWindow[i1].size();
	int len2 =  allWindow[i2].size();
	if(len1==len2) return i1<i2;
	else return len1<len2;
}



int main(){
	// 我都以分钟为单位长度 
	int beginTime = 8*60,endTime = 17*60;
	cin>>N>>M>>K>>Q;
	// 初始化 
	for(int i=0;i<N;i++){
		window[i] = -1;
		queueIndexList[i] = i;
	}
	for(int i=1;i<=K;i++){
		cin>>cus[i].needTime;
		cus[i].finishTime = -1;
		cus[i].startTime = -1;
		cus[i].index = i;
	}
	//输入查询列表 
	for(int i=0;i<Q;i++) cin>>queryList[i];
	
	int time=beginTime;
	// 代表下一个入队的人编号 
	int nextIndex = 1;
	int temp;
	for(time = beginTime;time<endTime;time++){
		//送客
		for(int i=0;i<N;i++){
			if(window[i]!=-1){
				temp = window[i];
				if(cus[temp].finishTime==time){
					//该走了
					allWindow[i].pop();
					// 窗口空闲 
					window[i] = -1;
				}
			}
		}
		
		// 入队
		// 先按排(i) 再按列(j)来看 
		for(int i=1;i<=M;i++){
			for(int j=0;j<N;j++){
				// 拿到当前队列的长度 
				temp = allWindow[j].size();
				// 如果当前看的排数中 当前队伍长度是小于当前排数的
				// 那说明在每队人数=排数时,这一列是序号最小且最短的队伍 
				// 那么黄线外的第一个人就应该进来排队了 
				if(temp<i&&nextIndex<=K){
					allWindow[j].push(cus[nextIndex]);
					nextIndex++;
				}
			}
		} 
		
		// 设置时间2 
		for(int i=0;i<N;i++){
			// 拿到队列编号 
			if(window[i]==-1){
				//取出编号 占用窗口 
				window[i] = allWindow[i].front().index;
			}
			if(cus[window[i]].startTime==-1){
				cus[window[i]].startTime = time;
				cus[window[i]].finishTime = time + cus[window[i]].needTime;
			}
		}

	}
	
	int quInd;
	int hh,mm;
	for(int i=0;i<Q;i++){
		quInd = queryList[i];
		if(cus[quInd].startTime==-1) cout<<"Sorry";
		else{
			hh = cus[quInd].finishTime/60;
			mm = cus[quInd].finishTime%60;
			printf("%02d:%02d",hh,mm);
		}
		cout<<endl;
	}
	
	
	return 0;
}
