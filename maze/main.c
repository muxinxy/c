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
               {0,0,0,0,0,0,0,0,0,0}};//有结果
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
               {0,0,0,0,0,0,0,0,0,0}};//无结果
*/
typedef struct{
	int x;
	int y;
}PosType;//表示地点

typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;//表示路径中的通块

typedef struct{
    SElemType *elem;
    int top;
}SqStack;//表示栈

void ShowMaze(){//输出迷宫
    int i,j;
    for(i=0;i<MAXLENGTH;i++){
        for(j=0;j<MAXLENGTH;j++)
        {
            printf("%4d",maze[i][j]);
        }
        printf("\n");
	}
}

int InitStack(SqStack *S){//初始化栈
    S->elem=(SElemType*)malloc(MAXLENGTH*MAXLENGTH*sizeof(SElemType));
    if(!S->elem)
        return 0;
    S->top=0;
    return 1;
}

int Push(SqStack *S,SElemType e){//入栈
    if(S->top>=MAXLENGTH*MAXLENGTH)
       return 0;
    S->elem[S->top++]=e;
    return 1;}

int Pop(SqStack *S,SElemType *e){//出栈
    if(S->top<=0)
        return 0;
    *e=S->elem[--S->top];
    return 1;
}

 int StackEmpty(SqStack *S){//判断栈是否为空
     if(S->top==0)
        return 1;
     else
        return 0;
}

PosType NextPos(PosType curpos, int di){//探索下一个位置
	PosType p;
	switch(di){//1234分别表示东南西北，逆时针方向
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

int Pass(PosType curpos){//判断是否可通
	if(maze[curpos.x][curpos.y]==1)
		return 1;
	else
		return 0;
}

void FootPrint(PosType curpos, int curstep){//留下路径顺序
	maze[curpos.x][curpos.y]=curstep;
}

void MarkPrint(PosType curpos){//留下不可通的脚印
	maze[curpos.x][curpos.y]=-1;
}

int MazePath(PosType start, PosType end){//寻找路径
	SqStack *S=(SqStack *)malloc(sizeof(SqStack));
	InitStack(S);
	PosType curpos;
	curpos.x=start.x;
	curpos.y=start.y;//入口位置就是当前位置
    SElemType e;
	int curstep=1;
	do{
		if(Pass(curpos)){
			FootPrint(curpos,curstep);
			e.ord=curstep;
			e.seat.x=curpos.x;
			e.seat.y=curpos.y;
			e.di=1;
			Push(S, e);//可通就入栈
			if(curpos.x==end.x && curpos.y==end.y){//出口位置结束
                free(S);
                return 1;
			}
			curpos=NextPos(curpos, 1);//探索下一个位置
			curstep++;
		}else{
			if(!StackEmpty(S)){
				Pop(S, &e);//不可通就出栈，退回上一步
				while(e.di==4 && !StackEmpty(S)){
					MarkPrint(e.seat);
					Pop(S, &e);//四个方向都探索完就继续出栈
					curstep--;
				}
				if(e.di<4){//有方向没被探索，探索下一个方向
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
