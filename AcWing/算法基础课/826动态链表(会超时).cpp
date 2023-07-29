#include<stdio.h>
#include<stdlib.h>

int embed_ind; 
typedef struct LinkNode{
	int val;
	int idx;// 插入位序 
	LinkNode *next;
}*LinkList,LinkNode;

int M;

void initLinkList(LinkList &s){
	embed_ind = 0;
	// 建立头节点 
	s = (LinkNode *)malloc(sizeof(LinkNode));
	s->val = 0;
	s->next = NULL;
	s->idx = embed_ind;
}

// 头插操作 
void insertHead(LinkList &s,int v){
	LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
	embed_ind++;
	node->idx = embed_ind;
	node->val = v;
	node->next = s->next;
	s->next = node;
}

// 删除插入编号为k的 
void deleteK(LinkList &s,int k){
	if(k==0){
		// 删除头节点
		LinkNode *p = s;
		s = s->next;
		free(p);
		return ;
	}
	LinkNode *p = s->next;
	while(p!=NULL){
		// 满足条件,删除该节点后面的节点 
		if(p->idx == k){
			LinkNode *q = p->next;
			p->next = q->next;
			// 释放掉删除节点的内存空间 
			free(q);
			break; 
		}
		p = p->next;
	}
}

// 在第k个插入的数后面插入 
void insertAfterK(LinkList &s,int k,int v){
	LinkNode *p = s->next;
	while(p!=NULL){
		// 找到了 
		if(p->idx==k){
			LinkNode *t = (LinkNode *)malloc(sizeof(LinkNode));
			t->next = p->next;
			t->val = v;
			embed_ind++;
			t->idx = embed_ind;
			p->next = t;
			break;
		}
		p = p->next;
	}
}

int main(){
	char op;
	int a,b,c;
	LinkList head;
	initLinkList(head);
	scanf("%d\n",&M);
	while(M--){
		scanf("%c",&op);
		if(op=='H'){
			scanf(" %d",&a);
			insertHead(head,a);
		}else if(op=='I'){
			scanf("%d %d",&a,&b);
			insertAfterK(head,a,b);
		}else if(op=='D'){
			scanf("%d",&c);
			deleteK(head,c);
		}
		getchar();
	}
	
	LinkNode *p = head->next;
	while(p!=NULL){
		printf("%d",p->val);
		if(p->next!=NULL) printf(" ");
		p = p->next;
	}
	printf("\n");
	
	return 0;
}
