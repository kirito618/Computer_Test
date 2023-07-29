#include<bits/stdc++.h>

using namespace std;

struct players{
	// 时间的单位都是秒 
	int arriveTime;
	int need;
	int tag;
	int leaveTime=0;
	int serveTime=0;
};

struct tables{
	bool ifVip=false;
	// 记录服务的组数
	int serveCount = 0;
	int serve = -1;
};

players p[10001];
tables t[101]; 
// N为多少对玩家  K为多少张桌子  M为桌子里面VIP桌子的个数 M<K 
int N,K,M;

bool comp(players a,players b){
	return a.arriveTime<b.arriveTime;
}

void printMyFormat(int Time){
	printf("%02d:%02d:%02d",Time/3600,Time%3600/60,Time%60);
}


int main(){
	int hh,mm,ss,Time,j;
	int key,temp,need,tag,next;
	int beginTime = 8*3600;
	int endTime = 21*3600;
	char tt;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>hh>>tt>>mm>>tt>>ss>>need>>tag;
		if(need>120) need = 120;
		//记录到达时间 
		p[i].arriveTime = hh*3600+mm*60+ss;
		p[i].need = need*60;
		p[i].tag = tag;
	}
	cin>>K>>M;
	for(int i=1;i<=M;i++){
		cin>>temp;
		t[temp].ifVip=true;
	}
	
	sort(p,p+N,comp);
	
	next = 0;
	// 普通队与vip队 
	queue<int> commonList;
	queue<int> vipList;
	vector<int> serveList; 
	for(Time=beginTime;Time<endTime;Time++){
		// 送客 
		for(int i=1;i<=K;i++){
			if(t[i].serve>=0){
				//说明有人服务
				j = t[i].serve;
				if(p[j].leaveTime==Time){
					t[i].serve = -1;
				} 
			}
		}
		
		// ---------------分配桌子----------------- 
		//  分配之前 先将当前时刻已经到达的人加入到队列中去
		// vip可以在vip队列里排  也可以在普通人队列里排 
		while(next<N&&p[next].arriveTime==Time){
			commonList.push(next);
			if(p[next].tag==1) vipList.push(next);
			next++;
		}
		
		// 先处理vip桌子
		while(vipList.size()&&p[vipList.front()].serveTime!=0) vipList.pop();
		for(int i=1;i<=K;i++){
			if(!t[i].ifVip) continue;
			if(t[i].serve==-1){
				if(vipList.size()){
					j = vipList.front();
					t[i].serve = j;
					// 放到被服务的队列中去 
					serveList.push_back(j);
					t[i].serveCount++;
					p[j].serveTime = Time;
					p[j].leaveTime = Time + p[j].need;
					while(vipList.size()!=0&&p[vipList.front()].serveTime!=0){
						vipList.pop();
					}
				}
			}
		}
		
		// 处理普通桌子 以及 没有人占用的vip桌子 
		while(commonList.size()&&p[commonList.front()].serveTime!=0) commonList.pop();
		for(int i=1;i<=K;i++){
			if(t[i].serve==-1){
				if(commonList.size()){
					j = commonList.front();
					t[i].serve = j;
					// 放到被服务的队列中去 
					serveList.push_back(j);
					t[i].serveCount++;
					p[j].serveTime = Time;
					p[j].leaveTime = Time + p[j].need;
					while(commonList.size()!=0&&p[commonList.front()].serveTime!=0){
						commonList.pop();
					}
				}
			}
		}
		
		// 迎客 
		for(int i=1;i<=K;i++){
			if(t[i].serve>=0){
				j = t[i].serve;
				if(p[j].leaveTime==0){
					p[j].leaveTime = Time + p[j].need;
				}
			}
		}
	}
	
	for(int i:serveList){
		printMyFormat(p[i].arriveTime);
		cout<<" ";
		printMyFormat(p[i].serveTime);
		cout<<" ";
		cout<<(p[i].serveTime-p[i].arriveTime+30)/60<<endl;
	}
	
	for(int i=1;i<=K;i++){
		cout<<t[i].serveCount;
		if(i!=K) cout<<" ";
		else cout<<endl;
	}
	
	return 0;
} 
