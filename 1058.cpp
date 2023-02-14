#include<iostream>
using namespace std;

int main(){
	long long a,b,c,x,y,z;
	long long jin1 = 0,jin2 = 0,jin3 = 0;
	long long d,e,f;
	cin>>a;
	getchar();
	cin>>b;
	getchar();
	cin>>c>>x;
	getchar();
	cin>>y;
	getchar();
	cin>>z;
	f = (c+z)%29;
	jin1 = (c+z)/29;
	e = (b+y+jin1)%17;
	jin2 = (b+y+jin1)/17;
	//d = (a+x+jin2)%10000001;
	d = (a+x+jin2);
	cout<<d<<"."<<e<<"."<<f<<endl;
	return 0;
}
