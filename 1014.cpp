#include<iostream>
#include<vector>
using namespace std;

int N,M,K,Q;// N是窗口数，M是每个窗口队列的最大长度，K是顾客数，Q是想要计算完成时间的顾客数
int time[1001];// 代表的是 i号顾客所需服务时间
int HH[1001],MM[1001];
int HH_list[20],MM_list[20];
vector<int> searchList; // 存放要计算时间的所有顾客 
vector<int> frontList[20];// 存放各个窗口的队列(黄线内)
vector<int> waitList;// 存放黄线外的等待队列 

// 递归计算每个顾客的时间。
void dfs(int listIndex,int cur){
	if(frontList[listIndex][0]==cur){
		//当前是某队列的第一个顾客
		
	}
	
	
}

void formatResult(int HH,int MM){ 
	if(HH<17){
		if(HH<10){
			cout<<"0";
		}
		cout<<HH<<":";
		if(MM<10){
			cout<<"0";
		}
		cout<<MM<<endl;
	}else{
		cout<<"Sorry";
	}
}

int main(){
	int temp,HH,MM;
	int neglect; // 表示现在还没被服务的顾客的编号 
	bool flag = true;
	cin>>N>>M>>K>>Q;
	// 输入各个顾客所需的服务时间 
	for(int i=1;i<=K;i++){
		cin>>time[i];
	}
	// 设置起始时间 
	for(int i=0;i<N;i++) {
		HH_list[i] = 8;
		MM_list[i] = 0;
	}
	// 接下来输入需要计算时间的顾客并保存起来 
	for(int i=0;i<Q;i++){
		cin>>temp;
		searchList.push_back(temp);
	}
	
	for(int i=1;i-1<N&&i<=K;i++){
		frontList[i-1].push_back(i);
		neglect = i+1;
	}
	
	while(neglect<=K){
		//推进一轮，把每个队的第一个都处理完，更新每个队列的起始时间 
		for(int i=0;i<N;i++){
			if(frontList[i].length()==0) continue;
			temp = frontList[i][0];
			// 将这个元素从队列中删掉 
			frontList[i].erase(frontList[i].begin());
			HH_list[i] += time[temp]/60;
			MM_list[i] += time[temp]%60;
			if(MM_list[i]>=60){
				MM_list[i] = MM_list[i]%60;
				HH_list[i]++;
			}
			// 更新被处理者的完成时间
			HH[temp] = HH_list[i];
			MM[temp] = MM_list[i];
		}
		
		
		// 找到目前最短的那个队
	    for(int i=0,min = 0;i<N;i++){
	    	if(frontList[i].length()<frontList[min].length()){
	    		min = i;
			}
		}
		if(frontList[min].length()==M){
			// 说明最短的那一队都没地方了 
			break;
		}
		
		
		HH[neglect] 
		
	}
	
	for(int )

	return 0;
} 
