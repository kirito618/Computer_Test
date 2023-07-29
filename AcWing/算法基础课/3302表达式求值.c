#include<stdio.h>
#include<string.h>

char input[100010];
// prior[i]表示ascII码为i的优先级
int prior[2000];// 优先级数组
char char_st[100010];
int num_st[10001];
int top_c = 0,top_n = 0;

void init(){
    prior['+'] = 1;
    prior['-'] = 1;
    prior['*'] = 2;
    prior['/'] = 2;
    prior['('] = 0;
}

int get_res(char op){
    int a,b,res;
    b = num_st[top_n--];
    a = num_st[top_n--];
    if(op=='+') res = a+b;
    else if(op=='-') res = a-b;
    else if(op=='*') res = a*b;
    else if(op=='/') res = a/b;
    //printf("%d %c %d = %d\n",a,op,b,res);
    return res;
}


int main(){
    scanf("%s",input);
    int len = strlen(input);
    init();
    int i = 0,t;
    char c;
    while(i<len){
        if(input[i]>='0'&&input[i]<='9'){
            t = 0;
            while(i<len&&input[i]>='0'&&input[i]<='9'){
                t = t * 10 + (input[i]-'0');
                i++;
            }
            num_st[++top_n] = t;
        }else{
            if(input[i]=='(') char_st[++top_c] = input[i];
            else if(input[i]==')'){
                while(top_c>0&&char_st[top_c]!='('){
                    // 传入操作，返回运算结果
                    t = get_res(char_st[top_c--]);
                    // 计算结果入栈
                    num_st[++top_n] = t;
                }
                // 此时栈顶为(，出栈
                top_c--;
            }else{
                // 是运算符
                c = char_st[top_c];
                while(top_c>0&&prior[c]>=prior[input[i]]){
                    // 传入操作，返回运算结果
                    t = get_res(c);
                    c = char_st[--top_c];
                    // 计算结果入栈
                    num_st[++top_n] = t;
                }
                char_st[++top_c] = input[i];
            }
            i++;
        }
    }

    while(top_c>0){
        t = get_res(char_st[top_c--]);
        num_st[++top_n] = t;
    }
    printf("%d\n",num_st[top_n]);

    return 0;
}
