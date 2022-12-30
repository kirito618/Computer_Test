#include<iostream>
#include<string>
using namespace std;

//�����봮ת���ɶ�Ӧ��ʮ������
long long toTenRedix(string N,int redix){
    long long tempNum = 0;
    long long result = 0;
    // ���Ȩ��
    long long right = 1;
    for(long long i=N.length()-1;i>=0;i--){
        if(N[i]>='a'&&N[i]<='z') tempNum = N[i] - 'a' + 10;
        else{
            tempNum = N[i] - '0';
        }
        if(tempNum >=redix){
            return -1;
        }
        result += tempNum*right;
        //Ȩ������
        right *= redix;
    }
    return result;
}

int main(){
    string N[2];
    bool flag = false;
    int tag,redix,other;
    long long result,mid;
    long long temp,know;
    cin>>N[0]>>N[1]>>tag>>redix;
    //tag����֪���Ƶ��Ǹ����ı��,other������һ�����ı��
    other = tag==1?2:1;

    //����֪���Ǹ�����ת��ʮ����
    know = toTenRedix(N[tag-1],redix);

    for(int r = 1;r<=100000;r++){
        temp = toTenRedix(N[other-1],r);
        if(temp > know){
            break;
        }else if(temp==know){
            //�ҵ��ˣ��ڵ�ǰ�����¶��߿������
            flag = true;
            result = r;
            break;
        }
    }


    if(temp<know){
      long long minRedix = 100001;
        //���������ö��ַ��ҳ��������ĸ��������������������
      for(long long low = 1,high = 9223372036854775;low<=high;){
          mid = (low + high)/2;
          temp = toTenRedix(N[other-1],mid);
          if(temp > know){
            high = mid - 1;
          }else if(temp < know){
            low = mid + 1;
          }else{
            //�ҵ��ˣ��ڵ�ǰ�����¶��߿������
            flag = true;
            if(mid<minRedix){
                minRedix = mid;
            }
          }
      }
      result = minRedix;
    }


    if(flag){
        cout<<result<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }

    return 0;
}
