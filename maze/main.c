#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 10
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int MazeType[MAXLENGTH][MAXLENGTH];

MazeType maze={{0,0,0,0,0,0,0,0,0,0},
               {0,1,1,0,1,1,1,0,1,0},
               {0,1,1,0,1,1,1,0,1,0},
               {0,1,1,1,1,0,0,1,1,0},
               {0,1,0,0,0,1,1,1,1,0},
               {0,1,1,1,0,1,1,1,1,0},
               {0,1,0,1,1,1,0,1,1,0},
               {0,1,0,0,0,1,0,0,1,0},
               {0,0,1,1,1,1,1,1,1,0},
               {0,0,0,0,0,0,0,0,0,0}};//�н��
/*
MazeType maze={{0,0,0,0,0,0,0,0,0,0},
               {0,1,1,0,1,1,1,0,1,0},
               {0,1,1,0,1,1,1,0,1,0},
               {0,1,1,1,1,0,0,1,1,0},
               {0,0,0,0,0,1,1,1,1,0},
               {0,1,1,1,0,1,1,1,1,0},
               {0,1,0,1,1,1,0,1,1,0},
               {0,1,0,0,0,1,0,0,1,0},
               {0,0,1,1,1,1,1,1,1,0},
               {0,0,0,0,0,0,0,0,0,0}};//�޽��
*/
typedef struct{
	int x;
	int y;
}PosType;//��ʾ�ص�

typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;//��ʾ·���е�ͨ��

typedef struct{
    SElemType *elem;
    int top;
}SqStack;//��ʾջ

void ShowMaze(){//����Թ�
    int i,j;
    for(i=0;i<MAXLENGTH;i++){
        for(j=0;j<MAXLENGTH;j++)
        {
            printf("%4d",maze[i][j]);
        }
        printf("\n");
	}
}

int InitStack(SqStack *S){//��ʼ��ջ
    S->elem=(SElemType*)malloc(MAXLENGTH*MAXLENGTH*sizeof(SElemType));
    if(!S->elem)
        return 0;
    S->top=0;
    return 1;
}

int Push(SqStack *S,SElemType e){//��ջ
    if(S->top>=MAXLENGTH*MAXLENGTH)
       return 0;
    S->elem[S->top++]=e;
    return 1;}

int Pop(SqStack *S,SElemType *e){//��ջ
    if(S->top<=0)
        return 0;
    *e=S->elem[--S->top];
    return 1;
}

 int StackEmpty(SqStack *S){//�ж�ջ�Ƿ�Ϊ��
     if(S->top==0)
        return 1;
     else
        return 0;
}

PosType NextPos(PosType curpos, int di){//̽����һ��λ��
	PosType p;
	switch(di){//1234�ֱ��ʾ������������ʱ�뷽��
		case 1:
			p.x=curpos.x;
			p.y=curpos.y+1;
			break;
		case 2:
			p.x=curpos.x+1;
			p.y=curpos.y;
			break;
		case 3:
			p.x=curpos.x;
			p.y=curpos.y-1;
			break;
		case 4:
			p.x=curpos.x-1;
			p.y=curpos.y;
			break;
	}
	return p;
}

int Pass(PosType curpos){//�ж��Ƿ��ͨ
	if(maze[curpos.x][curpos.y]==1)
		return 1;
	else
		return 0;
}

void FootPrint(PosType curpos, int curstep){//����·��˳��
	maze[curpos.x][curpos.y]=curstep;
}

void MarkPrint(PosType curpos){//���²���ͨ�Ľ�ӡ
	maze[curpos.x][curpos.y]=-1;
}

int MazePath(PosType start, PosType end){//Ѱ��·��
	SqStack *S=(SqStack *)malloc(sizeof(SqStack));
	InitStack(S);
	PosType curpos;
	curpos.x=start.x;
	curpos.y=start.y;//���λ�þ��ǵ�ǰλ��
    SElemType e;
	int curstep=1;
	do{
		if(Pass(curpos)){
			FootPrint(curpos,curstep);
			e.ord=curstep;
			e.seat.x=curpos.x;
			e.seat.y=curpos.y;
			e.di=1;
			Push(S, e);//��ͨ����ջ
			if(curpos.x==end.x && curpos.y==end.y){//����λ�ý���
                free(S);
                return 1;
			}
			curpos=NextPos(curpos, 1);//̽����һ��λ��
			curstep++;
		}else{
			if(!StackEmpty(S)){
				Pop(S, &e);//����ͨ�ͳ�ջ���˻���һ��
				while(e.di==4 && !StackEmpty(S)){
					MarkPrint(e.seat);
					Pop(S, &e);//�ĸ�����̽����ͼ�����ջ
					curstep--;
				}
				if(e.di<4){//�з���û��̽����̽����һ������
					e.di++;
					Push(S, e);
					curpos=NextPos(e.seat, e.di);
				}
			}
		}
	}while(!StackEmpty(S));
	free(S);
	return 0;
}

int main(){
	PosType start;
	start.x=start.y=1;
	PosType end;
	end.x=end.y=8;
	printf("Maze:\n");
	ShowMaze();
	if(MazePath(start, end)){
        printf("\nResult:\n");
        ShowMaze();
	}else{
        printf("\nNo Result\n");
	}
	return 0;
}
