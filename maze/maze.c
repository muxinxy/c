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
               {0,0,0,0,0,0,0,0,0,0}};

typedef struct{
	int x;
	int y;
}PosType;

typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;

typedef struct

{

SElemType *elem;

  int top;

}SqStack;

void ShowMaze(){
    int i,j;
    for(i=0;i<MAXLENGTH;i++){
        for(j=0;j<MAXLENGTH;j++)
        {
            printf("%4d",maze[i][j]);
        }
        printf("\n");
	}
}

int InitStack(SqStack *S){
    S->elem=(SElemType*)malloc(MAXLENGTH*MAXLENGTH*sizeof(SElemType));
    if(!S->elem)
        return 0;
    S->top=0;
    return 1;
}

int Push(SqStack *S,SElemType e){
    if(S->top>=MAXLENGTH*MAXLENGTH)
       return 0;
    S->elem[S->top++]=e;
    return 1;}

int Pop(SqStack *S,SElemType *e){
    if(S->top<=0)
        return 0;
    *e=S->elem[--S->top];
    return 1;
}

 int StackEmpty(SqStack *S){
     if(S->top==0)
        return 1;
     else
        return 0;
}

PosType NextPos(PosType curpos, int di){
	PosType p;
	switch(di){
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

int Pass(PosType curpos){
	if(maze[curpos.x][curpos.y]==1)
		return 1;
	else
		return 0;
}

void FootPrint(PosType curpos, int curstep){
	maze[curpos.x][curpos.y]=curstep;
}

void MarkPrint(PosType curpos){
	maze[curpos.x][curpos.y]=-1;
}

int MazePath(PosType start, PosType end){
	SqStack *S=(SqStack *)malloc(sizeof(SqStack));
	InitStack(S);
	PosType curpos;
	curpos.x=start.x;
	curpos.y=start.y;
    SElemType e;
	int curstep=1;
	do{
		if(Pass(curpos)){
			FootPrint(curpos,curstep);
			e.ord=curstep;
			e.seat.x=curpos.x;
			e.seat.y=curpos.y;
			e.di=1;
			Push(S, e);
			if(curpos.x==end.x && curpos.y==end.y){
                free(S);
                return 1;
			}
			curpos=NextPos(curpos, 1);
			curstep++;
		}else{
			if(!StackEmpty(S)){
				Pop(S, &e);
				while(e.di==4 && !StackEmpty(S)){
					MarkPrint(e.seat);
					Pop(S, &e);
					curstep--;
				}
				if(e.di<4){
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
	ShowMaze();
	if(MazePath(start, end)){
        printf("\nResult:\n");
        ShowMaze();
	}else{
        printf("\nNo Result\n");
	}
	return 0;
}
