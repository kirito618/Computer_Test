#include<iostream>
#include<vector>
using namespace std;

int N,M,K,Q;// N�Ǵ�������M��ÿ�����ڶ��е���󳤶ȣ�K�ǹ˿�����Q����Ҫ�������ʱ��Ĺ˿���
int time[1001];// ������� i�Ź˿��������ʱ��
int HH[1001],MM[1001];
int HH_list[20],MM_list[20];
vector<int> searchList; // ���Ҫ����ʱ������й˿� 
vector<int> frontList[20];// ��Ÿ������ڵĶ���(������)
vector<int> waitList;// ��Ż�����ĵȴ����� 

// �ݹ����ÿ���˿͵�ʱ�䡣
void dfs(int listIndex,int cur){
	if(frontList[listIndex][0]==cur){
		//��ǰ��ĳ���еĵ�һ���˿�
		
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
	int neglect; // ��ʾ���ڻ�û������Ĺ˿͵ı�� 
	bool flag = true;
	cin>>N>>M>>K>>Q;
	// ��������˿�����ķ���ʱ�� 
	for(int i=1;i<=K;i++){
		cin>>time[i];
	}
	// ������ʼʱ�� 
	for(int i=0;i<N;i++) {
		HH_list[i] = 8;
		MM_list[i] = 0;
	}
	// ������������Ҫ����ʱ��Ĺ˿Ͳ��������� 
	for(int i=0;i<Q;i++){
		cin>>temp;
		searchList.push_back(temp);
	}
	
	for(int i=1;i-1<N&&i<=K;i++){
		frontList[i-1].push_back(i);
		neglect = i+1;
	}
	
	while(neglect<=K){
		//�ƽ�һ�֣���ÿ���ӵĵ�һ���������꣬����ÿ�����е���ʼʱ�� 
		for(int i=0;i<N;i++){
			if(frontList[i].length()==0) continue;
			temp = frontList[i][0];
			// �����Ԫ�شӶ�����ɾ�� 
			frontList[i].erase(frontList[i].begin());
			HH_list[i] += time[temp]/60;
			MM_list[i] += time[temp]%60;
			if(MM_list[i]>=60){
				MM_list[i] = MM_list[i]%60;
				HH_list[i]++;
			}
			// ���±������ߵ����ʱ��
			HH[temp] = HH_list[i];
			MM[temp] = MM_list[i];
		}
		
		
		// �ҵ�Ŀǰ��̵��Ǹ���
	    for(int i=0,min = 0;i<N;i++){
	    	if(frontList[i].length()<frontList[min].length()){
	    		min = i;
			}
		}
		if(frontList[min].length()==M){
			// ˵����̵���һ�Ӷ�û�ط��� 
			break;
		}
		
		
		HH[neglect] 
		
	}
	
	for(int )

	return 0;
} 
