#include<stdio.h>
char P[100010],S[100010],ne[100010];
int n,m;

int main(){
    int i,j;
    scanf("%d\n%s",&n,P+1);
    scanf("%d\n%s",&m,S+1);
    ne[0] = 0;
    ne[1] = 0;
    // ��ʼ��next����
    // ��2��ʼ����Ϊֻ�г���Ϊ2���ϲŻ���ǰ��׺
    for(i=2,j=0;i<=n;i++){
        while(j>0&&P[j+1]!=P[i]){
            j = ne[j];
        }
        if(P[j+1]==P[i]) j++;
        ne[i] = j;
    }

    for(i=1,j=0;i<=m;i++){
        while(j>0&&P[j+1]!=S[i]) j = ne[j];
        if(P[j+1]==S[i]) j++;
        if(j==n){
            // �ҵ���һ��ƥ��λ��,���Ѿ�ƥ����nλ�ַ�
            printf("%d ",i-n);
            // ����λ��
            j = ne[j];
        }
    }

    return 0;
}
