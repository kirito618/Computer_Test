#include<iostream>
#include<string>

using namespace std;

// �ж��º����Ƿ�Ϸ� 
bool valid(int mm,int dd){
	if(mm>12||mm<=0||dd<=0||dd>31) return false;
	if(mm==4||mm==6||mm==9||mm==11){
		if(dd>30) return false;
	}
	if(mm==2){
		if(dd>29) return false;
	}
	return true;
}

int main(){
	int N,tempYY;
	cin>>N;
	int yy = N/10000;
	int mm = N/100%100;
	int dd = N%100;
	int y1,y2,y3,y4;
	bool first = true;
	bool firstAB = true;
	while(yy<=9999){
		y1 = yy%10;
		y2 = yy/10%10;
		y3 = yy/100%10;
		y4 = yy/1000%10;
		tempYY = yy*10000 + y1*1000+y2*100+y3*10+y4;
		if(tempYY==N) continue;
		if(valid(y1*10+y2,y3*10+y4)){
			//�ǻ��Ĵ�
			if(first){
				//�ǵ�һ�����Ĵ�
				cout<<tempYY<<endl;
				first = false;
			}
			if(y4==y2&&y3==y1){
				//ABABBABA��
				if(firstAB){
					cout<<tempYY<<endl;
					firstAB = false;
					break;
				}
			}
		}
		yy++;
	}
	
	return 0;
} 
