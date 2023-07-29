#include<iostream>
#include<algorithm>
using namespace std;
int Nc,Np;
int a[100010],b[100010];
const int MAX = 110;// 选了就标记成MAX 

bool comp(int a,int b){
	if(a*b>0){
		return (a*a)>(b*b);
	}else{
		return a>b;
	}
}

// 我自己写滴  AC了但是最大时间200ms 
void method1(){
	// 正数大找大，负数找负数绝对值最小的 
	int x=0,y=0,lastP=-1,lastN=0;
	int endP=0,endN=0;
	int back=0;
	// 按从大到小排列 
	sort(a,a+Nc,comp);
	sort(b,b+Np,comp);
	while(lastN<Np&&b[lastN]>=0) lastN++;
	if(lastN<Np) lastN--;
	
	while(x<Nc){
		if(a[x]>0){
			// 找到上一个配对的正数位置的下一个 
			y = lastP+1;
			if(y<Nc&&b[y]>0){
				lastP = y;
				back+=a[x]*b[y];
			}
		}else if(a[x]<0){
			// 找到上一个配对的负数位置的下一个 
			y = lastN+1;
			if(y<Np&&b[y]<0){
				lastN = y;
				back+=a[x]*b[y];
			}
		}
		x++;
	}
	cout<<back<<endl;
}

//yxc的策略，从小到大排序，负数小配小，正数大配大 
void method2(){
	int res = 0;
	sort(a,a+Nc);
	sort(b,b+Np);
	for(int i=0,j=0;i<Nc&&j<Np&&a[i]<0&&b[j]<0;j++,i++){
		res += a[i]*b[j];
	}
	
	for(int i=Nc-1,j=Np-1;i>=0&&j>=0&&a[i]>0&&b[j]>0;j--,i--){
		res += a[i]*b[j];
	}
	
	cout<<res<<endl;
}

int main(){
	cin>>Nc;
	for(int i=0;i<Nc;i++) cin>>a[i];
	cin>>Np;
	for(int i=0;i<Np;i++) cin>>b[i];
	method2();
	
	
	return 0;
} 
