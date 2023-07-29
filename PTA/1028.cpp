#include<iostream>
#include<string>
using namespace std;

//已AC！！！2022/1/22 
//第一版是直接冒泡暴力解决，得了20分，最后一个例子超时
//第二版改用快排优化，最后在限时间400ms的前提下以283ms通过 
struct student{
	string id;
	string name;
	int grade;
};
int N,C,j,k,index,l;
string temp1,temp2;
int temp3,temp4;
int id_num[100000];
student both[100000];

void quick_sort(int left,int right,int column){
	if(left>right) return;
	student temp;
	j = left;
	k = right;
	// 基准值 
	temp = both[left];
	temp1 = both[left].name;
	temp3 = id_num[left];
	temp4 = both[left].grade;
	
	if(column==1){
		while(j<k){
			//此时找到一个比基准值小的。
			while(id_num[k]>=temp3&&j<k){
				k--;
			}
			
			if(j<k){
				id_num[j] = id_num[k];
				both[j] = both[k];	
			}
			
			
			//此时找到一个比基准值大的。
			while(id_num[j]<=temp3&&j<k){
				j++;
			}
			if(j<k){
				id_num[k] = id_num[j];
				both[k] = both[j];	
			}
		}
	}else if(column==2){
		while(j<k){
			//此时找到一个比基准值小的。
			while(both[k].name>=temp1&&j<k){
				k--;
			}
			
			if(j<k){
				both[j] = both[k];
			}
			
			//此时找到一个比基准值大的。
			while(both[j].name<=temp1&&j<k){
				j++;
			}
			if(j<k){
				both[k] = both[j];
			}
		}
	}else{
		while(j<k){
			//此时找到一个比基准值小的。
			while(both[k].grade>=temp4&&j<k){
				k--;
			}
			
			if(j<k){
				both[j] = both[k];	
			}
			
			//此时找到一个比基准值大的。
			while(both[j].grade<=temp4&&j<k){
				j++;
			}
			if(j<k){
				both[k] = both[j];	
			}
		}
	}
	
	index = j;
	both[j] = temp;
	id_num[j] = temp3;
	// 在左边排一次，在右边排一次 
	quick_sort(left,index-1,column);
	quick_sort(index+1,right,column);
}


//string 转 int
int str_int(string input){
	int output = 0;
	for(int i=0;i<input.length();i++){
		output = output*10 + (input[i] - '0');
	}
	return output;
}


int main(){
	student temp;
	cin>>N>>C;
	// 输入数据 
	for(int i=0;i<N;i++){
		cin>>temp1>>temp2>>temp3;
		both[i].id = temp1;
		both[i].name = temp2;
		both[i].grade = temp3;
	}
	for(int i=0;i<N;i++){
		id_num[i] = str_int(both[i].id);
		
	}
//	if(C==1){
//		// 排id列
//		for(int i=0;i<N-1;i++){
//			for(int j=0;j<N-i-1;j++){
//				if(id_num[j]>id_num[j+1]){
//					temp3 = id_num[j];
//					id_num[j] = id_num[j+1];
//					id_num[j+1] = temp3; 
//					
//					temp = both[j];
//					both[j] = both[j+1];
//					both[j+1] = temp;
//				}
//			}
//		}
//	}else if(C==2){
//		// 排第二列
//		for(int i=0;i<N-1;i++){
//			for(int j=0;j<N-i-1;j++){
//				if(both[j].name>=both[j+1].name){
//					temp = both[j];
//					both[j] = both[j+1];
//					both[j+1] = temp;
//				}
//			}
//		}
//	}else{
//		// 排第三列
//		for(int i=0;i<N-1;i++){
//			for(int j=0;j<N-i-1;j++){
//				if(both[j].grade>both[j+1].grade){
//					temp = both[j];
//					both[j] = both[j+1];
//					both[j+1] = temp;
//				}
//			}
//		}
//	}
//	
	quick_sort(0,N-1,C);
	j=0;k=0;
	while(j<N){
		k=j;
		while(both[j].name==both[j+1].name){
			j++;
		}
		if(j!=k){
			//有重名，按照他们的id递增再排一次！ 
			quick_sort(k,j,1);	
		}
		j++;
	}
	
	for(int i=0;i<N;i++){
		cout<<both[i].id<<" "<<both[i].name<<" "<<both[i].grade<<endl;
	}
	return 0;
}
