#include<iostream>
#include<set>
using namespace std;
multiset<int> hoop;

int main(){
	int N,t,a,b;
	long long res;
	res = 0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&t);
		hoop.insert(t);
	}
	while(hoop.size()>1){
		a = *hoop.begin();
		hoop.erase(hoop.begin());
		b = *hoop.begin();
		hoop.erase(hoop.begin());
		res += a+b;
		hoop.insert(a+b); 
	}
	
	printf("%d\n",res);
	return 0;
}
