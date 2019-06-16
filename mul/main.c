#include <stdio.h>
#include <stdlib.h>

int n=0;//����ȫ�ֱ�����ʾ����ʽ������

typedef struct LNode{
	int coe;
	int exp;
	struct LNode *next;
}LNode,*LinkList;//���������ʾ����ʽ����

LinkList CreateList(){//��ʼ������ʽ
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

void ShowList(LinkList LHead){//�������ʽ
	printf("\nThe polynomial:\n%d",n);
	LHead=LHead->next;
	while(LHead){
		printf(",%d,%d",LHead->coe,LHead->exp);
		LHead=LHead->next;
	}
	printf("\n");
}

LinkList SortList(LinkList LHead){//�Զ���ʽ����ָ���ݼ�����ʹ��ѡ������
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

LinkList MulList(LinkList LHead1,LinkList LHead2){//����ʽ�˷��������
	int i,exp_max,coe=0;
	n=0;
	LinkList LHead3=(LinkList)malloc(sizeof(LNode));//����һ���µ����������洢�������ʽ
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
		exp_max=LHead1->next->exp+LHead2->next->exp;//�����������������
	//printf("exp_max=%d\n",exp_max);
	for(i=exp_max;i>=0;i--){//ͨ������ѭ�����㲢�ϲ�ͬ����
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
		if(coe!=0){//�������������������
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
	if(n>1)//����ʽֻ��һ���򲻽�������
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
