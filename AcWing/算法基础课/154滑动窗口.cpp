#include<stdio.h>
int n,k,hh,tt;
int arr[1000010],q[1000010];

// 输出窗口最小值,维护一个单调增队列,队首为最小值 
void method1(){
	int i,j;
	hh=0;tt=0;
	for(i=0;i<n;i++){
		// 判断队首元素是否还在当前窗口内,若不在则弹出 
		if(hh<tt&&i-k+1>q[hh]) hh++;
		// 从末尾向前把队列里所有比当前值大的值都清除 
		while(hh<tt&&arr[q[tt-1]]>=arr[i]) tt--;
		// 将当前值的下标存入队列
		q[tt++] = i;
		if(i>=k-1) printf("%d ",arr[q[hh]]); 
	} 
	puts("");
}

// 输出窗口最大值 
void method2(){
	int i,j;
	hh=0;tt=0;
	for(i=0;i<n;i++){
		// 判断队首元素是否还在当前窗口内,若不在则弹出 
		if(hh<tt&&i-k+1>q[hh]) hh++;
		// 从末尾向前把队列里所有比当前值大的值都清除 
		while(hh<tt&&arr[q[tt-1]]<=arr[i]) tt--;
		// 将当前值的下标存入队列
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
