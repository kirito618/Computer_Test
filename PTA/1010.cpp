#include<iostream>
#include<string>
using namespace std;

//将输入串转换成对应的十进制数
long long toTenRedix(string N,int redix){
    long long tempNum = 0;
    long long result = 0;
    // 最大权重
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
        //权重增大
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
    //tag是已知进制的那个数的编号,other就是另一个数的编号
    other = tag==1?2:1;

    //把已知的那个数先转成十进制
    know = toTenRedix(N[tag-1],redix);

    for(int r = 1;r<=100000;r++){
        temp = toTenRedix(N[other-1],r);
        if(temp > know){
            break;
        }else if(temp==know){
            //找到了，在当前进制下二者可以相等
            flag = true;
            result = r;
            break;
        }
    }


    if(temp<know){
      long long minRedix = 100001;
        //接下来利用二分法找出到底在哪个进制下两个数可以相等
      for(long long low = 1,high = 9223372036854775;low<=high;){
          mid = (low + high)/2;
          temp = toTenRedix(N[other-1],mid);
          if(temp > know){
            high = mid - 1;
          }else if(temp < know){
            low = mid + 1;
          }else{
            //找到了，在当前进制下二者可以相等
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
