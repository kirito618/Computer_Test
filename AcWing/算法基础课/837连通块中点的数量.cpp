#include<stdio.h>
int n,m;
int p[100010],num[100010];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	char op[2];
	int a,b;
	scanf("%d%d\n",&n,&m);
	// ����ΪӪ 
	for(int i=1;i<=n;i++){
		p[i] = i;
		num[i] = 1;
	} 
	while(m--){
		scanf("%s",op);
		if(op[0] == 'C'){
			// ab��һ���� 
			scanf("%d %d",&a,&b);
			// ��b���ڼ�������a��������
			if(find(a)!=find(b)){
				num[find(a)]+=num[find(b)];
				p[find(b)] = find(a);
			}
		}else if(op[1]=='1'){
			// ��ѯab�Ƿ���һ����ͨ���� 
			scanf("%d %d",&a,&b);
			if(find(a)==find(b)){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}else{
			// ѯ��a������ͨ���е������
			scanf("%d",&a);
			printf("%d\n",num[find(a)]);
		}
	}
	return 0;
}
