#include<stdio.h>
int n,k,hh,tt;
int arr[1000010],q[1000010];

// ���������Сֵ,ά��һ������������,����Ϊ��Сֵ 
void method1(){
	int i,j;
	hh=0;tt=0;
	for(i=0;i<n;i++){
		// �ж϶���Ԫ���Ƿ��ڵ�ǰ������,�������򵯳� 
		if(hh<tt&&i-k+1>q[hh]) hh++;
		// ��ĩβ��ǰ�Ѷ��������бȵ�ǰֵ���ֵ����� 
		while(hh<tt&&arr[q[tt-1]]>=arr[i]) tt--;
		// ����ǰֵ���±�������
		q[tt++] = i;
		if(i>=k-1) printf("%d ",arr[q[hh]]); 
	} 
	puts("");
}

// ����������ֵ 
void method2(){
	int i,j;
	hh=0;tt=0;
	for(i=0;i<n;i++){
		// �ж϶���Ԫ���Ƿ��ڵ�ǰ������,�������򵯳� 
		if(hh<tt&&i-k+1>q[hh]) hh++;
		// ��ĩβ��ǰ�Ѷ��������бȵ�ǰֵ���ֵ����� 
		while(hh<tt&&arr[q[tt-1]]<=arr[i]) tt--;
		// ����ǰֵ���±�������
		q[tt++] = i;
		if(i>=k-1) printf("%d ",arr[q[hh]]); 
	} 
	puts("");
}

int main(){
	int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	method1();
	method2();
	
	return 0;
} 
