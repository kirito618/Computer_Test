#include<iostream>
#include<algorithm>
using namespace std;
int Nc,Np;
int a[100010],b[100010];
const int MAX = 110;// ѡ�˾ͱ�ǳ�MAX 

bool comp(int a,int b){
	if(a*b>0){
		return (a*a)>(b*b);
	}else{
		return a>b;
	}
}

// ���Լ�д��  AC�˵������ʱ��200ms 
void method1(){
	// �������Ҵ󣬸����Ҹ�������ֵ��С�� 
	int x=0,y=0,lastP=-1,lastN=0;
	int endP=0,endN=0;
	int back=0;
	// ���Ӵ�С���� 
	sort(a,a+Nc,comp);
	sort(b,b+Np,comp);
	while(lastN<Np&&b[lastN]>=0) lastN++;
	if(lastN<Np) lastN--;
	
	while(x<Nc){
		if(a[x]>0){
			// �ҵ���һ����Ե�����λ�õ���һ�� 
			y = lastP+1;
			if(y<Nc&&b[y]>0){
				lastP = y;
				back+=a[x]*b[y];
			}
		}else if(a[x]<0){
			// �ҵ���һ����Եĸ���λ�õ���һ�� 
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

//yxc�Ĳ��ԣ���С�������򣬸���С��С����������� 
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
