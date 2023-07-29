#include <iostream>
#include <set>
#include <stack>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    stack<int> ss;
    multiset<int> mm;  //��¼��������
    multiset<int>::iterator midit;  //��λ��ָ��
    char cmd[11];
    while (n--){
        scanf("%s", cmd);
        //push
        if (cmd[1] == 'u'){
            int key;
            scanf("%d", &key);
            ss.push(key);
            mm.insert(key);
            if (mm.size()==1){
                midit = mm.begin();
            }
            else{
                if (mm.size()%2 == 0){
                    if (key < *midit){
                        midit--;
                    }
                }
                else{
                	//������>=����Ϊ������ȵ�ֵʱ����뵽����
                    if (key >= *midit){
                        midit++;
                    }
                }
            }
            
        }
        //pop
        else if (cmd[1] == 'o'){
            if (ss.empty()){
                printf("Invalid\n");
            }
            else{
                int key = ss.top();
                ss.pop();
                printf("%d\n", key);
                //ɾ����ֵ����*miditʱ�����ڿ������ظ�ֵ��Ҫ��ֹ��*midit����erase��
                if (key == *midit){
                    multiset<int>::iterator temp = midit;
                    if (mm.size()%2 == 0){
                        midit++;
                    }
                    else{
                        midit--;
                    }
                    mm.erase(temp);
                }
                //ɾ����������ֵ������midit��λ�ã�ֱ��ɾ֮
                else{
                    if (mm.size()%2 == 0){
                        if (key < *midit){
                            midit++;
                        }
                    }
                    else{
                        if (key > *midit){
                            midit--;
                        }
                    }
                    mm.erase(mm.find(key));
                }
            }
        }
        //PeekMedian
        else {
            if (ss.empty()){
                printf("Invalid\n");
            }
            else{
                printf("%d\n", *midit);
            }
        }
    }
    return 0;
}


