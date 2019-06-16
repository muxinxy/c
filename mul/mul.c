#include <stdio.h>
#include <stdlib.h>

int n=0;//定义全局变量表示多项式的项数

typedef struct LNode{
	int coe;
	int exp;
	struct LNode *next;
}LNode,*LinkList;//定义链表表示多项式的项

LinkList CreateList(){//初始化多项式
	int i,coe,exp;
	LinkList LHead=(LinkList)malloc(sizeof(LNode));
	LinkList LTail=NULL;
	if(LHead==NULL){
		printf("Memory allocation failure");
		exit(-1);
	}else{
		LTail=LHead;
		LHead->next=NULL;
		printf("Please input n:");
		scanf("%d",&n);
	}
	for(i=0;i<n;i++){
		LinkList p=(LinkList)malloc(sizeof(LNode));
		if(p==NULL){
		printf("Memory allocation failure");
		exit(-1);
		}else{
			printf("Please input coe,exp:");
			scanf("%d,%d",&coe,&exp);
			p->coe=coe;
			p->exp=exp;
			LTail->next=p;
			p->next=NULL;
			LTail=p;
		}
	}
	return LHead;
}

void ShowList(LinkList LHead){//输出多项式
	printf("\nThe polynomial:\n%d",n);
	LHead=LHead->next;
	while(LHead){
		printf(",%d,%d",LHead->coe,LHead->exp);
		LHead=LHead->next;
	}
	printf("\n");
}

LinkList SortList(LinkList LHead){//对多项式进行指数递减排序，使用选择排序法
	int t1,t2;
	LinkList p=LHead->next;
	LinkList q=p->next;;
	while(p->next!=NULL){
		q=p->next;
		while(q){
			if(p->exp<q->exp){
				t1=p->coe;
				t2=p->exp;
				p->coe=q->coe;
				p->exp=q->exp;
				q->coe=t1;
				q->exp=t2;
			}
			q=q->next;
		}
		p=p->next;
	}
	return LHead;
}

LinkList MulList(LinkList LHead1,LinkList LHead2){//多项式乘法计算过程
	int i,exp_max,coe=0;
	n=0;
	LinkList LHead3=(LinkList)malloc(sizeof(LNode));//创建一个新的链表用来存储结果多项式
	LinkList LTail=NULL;
	if(LHead3==NULL){
		printf("Memory allocation failure");
		exit(-1);
	}else{
		LTail=LHead3;
		LHead3->next=NULL;
	}
	LinkList p=LHead1->next;
	LinkList q=LHead2->next;
	if(LHead1->next!=NULL&&LHead2->next!=NULL)
		exp_max=LHead1->next->exp+LHead2->next->exp;//计算结果中项的最大次数
	//printf("exp_max=%d\n",exp_max);
	for(i=exp_max;i>=0;i--){//通过三重循环计算并合并同类项
		p=LHead1->next;
		q=LHead2->next;
		while(p){
			q=LHead2->next;
			while(q){
				if(p->exp+q->exp==i){
					coe+=p->coe*q->coe;
					//printf("i=%d\ncoe=%d\n",i,coe);
				}
				q=q->next;
			}
			p=p->next;
		}
		if(coe!=0){//将计算所得项存入链表
			LinkList t=(LinkList)malloc(sizeof(LNode));
			if(t==NULL){
				printf("Memory allocation failure");
				exit(-1);
			}else{
				t->coe=coe;
				t->exp=i;
				LTail->next=t;
				t->next=NULL;
				LTail=t;
				coe=0;
				n++;
			}
		}
	}
	return LHead3;
}

int main(int argc, char *argv[]) {
	LinkList La=CreateList();
	LinkList Lc;
	if(n>1)//多项式只有一项则不进行排序
		La=SortList(La);
	LinkList Lb=CreateList();
	if(n>1)
		Lb=SortList(Lb);
	//ShowList(La);
	//ShowList(Lb);
	Lc=MulList(La,Lb);
	ShowList(Lc);
	return 0;
}
