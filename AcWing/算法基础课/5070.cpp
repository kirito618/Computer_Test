#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int post[50010],in[50010],temp_p[50010],temp_i[50010],post_in[50010];
int cnt,N;

bool cmp1(int a,int b){
	return post[a]<post[b];
}

bool cmp2(int a,int b){
	return in[a]<in[b];
}


void build(int il,int ir,int pl,int pr){
	// ���ڵ� 
	int root = post[pr];
	// ���ڵ����������е��±� 
	int k = post_in[pr];
	
	// �ȸ�����,�������
	cnt++;
	if(cnt==N)
		printf("%d ",root); 
	// ������ 
	if(il<=k-1)
		build(il,k-1,pl,pl+k-1-il);
	// ������ 
	if(ir>=k+1)
		build(k+1,ir,pl+k-il,pr-1);
}

int main(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&post[i]);
		temp_p[i] = i;
	} 
	for(i=0;i<N;i++){
		scanf("%d",&in[i]);
		temp_i[i] = i;
	} 
	sort(temp_p,temp_p+N,cmp1);
	sort(temp_i,temp_i+N,cmp2);
	for(i=0;i<N;i++) post_in[temp_p[i]] = temp_i[i];
	
	build(0,N-1,0,N-1);
	
	return 0;
}
