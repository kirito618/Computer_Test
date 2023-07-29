#include<stdio.h>
#include<string.h>

int val[30],l[30],r[30];
char pre[30],in[30];
int pre_in[30];
int cnt=0;

int build(int pl,int pr,int il,int ir){
    if(pl>pr) return -1;
    int root = pre[pl];
    int k = pre_in[root-'A'];
    if(il<k)
        l[cnt] = build(pl+1,pl+k-il,il,k-1);
    if(ir>k)
        r[cnt] = build(pl+k-il+1,pr,k+1,ir);
    val[cnt++] = root;
    printf("%c",root);
    return root;
}

int main(){
    int lenP,lenI,i;
    while(scanf("%s",pre)!=EOF){
        cnt = 0;
        scanf("%s",in);
        lenP = strlen(pre);
        lenI = strlen(in);
        for(i=0;i<lenI;i++){
            pre_in[in[i]-'A'] = i;
        }
        build(0,lenP-1,0,lenI-1);
        printf("\n");
    }

    return 0;
}
