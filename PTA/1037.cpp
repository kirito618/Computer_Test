#include<bits/stdc++.h>

using namespace std;
int Nc,Np;
long long cous[100000];
long long pros[100000]; 
long long maximum = 0,temp;
long long sum = 0;
long long handle = 0;
long long count_fu = 0;
long long count1,count2;
//降序排序 
bool cmp(long long a,long long b){
	return a>b;
}

int main(){
	int index = 0,index2;
	cin>>Nc;
	for(int i=0;i<Nc;i++){
		cin>>cous[i];
	}
	cin>>Np;
	for(int i=0;i<Np;i++){
		cin>>pros[i];
	}
	
	sort(cous,cous+Nc,cmp);
	sort(pros,pros+Np,cmp);

    index = 0;
    index2 = 0;
    count1 = 0;
    count2 = 0;
    while(count1<(Nc-count_fu)&&count2<(Np-count_fu)){
    	temp = cous[index]*pros[index2];
    	if(temp>0){
    		while(temp>0){
				sum = sum + temp;
				index++;
				index2++;
				count1++;
				count2++;
				temp = cous[index]*pros[index2];
			}
		}else if(temp<0){
			while(temp<0){
				count_fu++;
				index++;
				index2++;
				temp = cous[index]*pros[index2];
			}
			//说明出现了负数
			index = Nc-1;
			index2 = Np-1;
			temp = cous[index]*pros[index2];
			if(temp<0){
				//已经退到最后了，仍然相乘小于0，说明最后两个数也不全是负的 
				break;
			}else if(temp>0){
				while(temp>0){
					sum = sum + temp;
					index--;
					index2--;
					count1++;
					count2++;
					temp = cous[index]*pros[index2];
				}
			}
		}else{
			while(cous[index]==0) {
				index++;
				count1++;
			}
			while(pros[index2]==0){
				index2++;
				count2++;
			}
		}
    	
	}
	cout<<sum;
	return 0;
}

// 4 2 1 -1
// 7 6 -2 -3
