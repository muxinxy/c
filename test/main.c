#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE 100
#define INCREMENT 10
typedef struct
{
int r;
int c;
}zuobiao;
typedef struct
{
int ord; //�ڵ�ǰ�����ϵġ���š�
zuobiao seat; //����
int di; //������һͨ���ķ���
}lujing;
typedef struct
{
int sz[10][10];
}Maze;
typedef struct SqStack
{
lujing *base;
lujing *top;
int size;
}SqStack;
int initStack(SqStack *s)
{
s->base = (lujing *)malloc(STACK_INIT_SIZE*sizeof(lujing) );
if(!s->base)
return -1;
s->top = s->base;
s->size = STACK_INIT_SIZE;
return 0;
}
int push(SqStack *s, lujing e)
{
if(s->top - s->base >= s->size)
{
s->base = (lujing *)realloc(s->base, (s->size+INCREMENT)*sizeof(lujing));
if(!s->base)
return -1;
s->top = s->base+s->size;
s->size += INCREMENT;
}
*s->top++ = e;
return 0;
}
int pop(SqStack *s,lujing *e)
{
if(s->top == s->base)
return -1;
*e = *(--s->top);
return 0;
}
int isEmpty(SqStack *s)
{
if(s->base == s->top)
return 1;
else
return 0;
}
int pass( Maze maze,zuobiao dqzb) {
if (maze.sz[dqzb.r][dqzb.c]==1)
return 1; // �����ǰλ���ǿ���ͨ�������� 1
else return 0; // ���򷵻� 0
}
void footPrint(Maze maze,zuobiao dqzb) {
maze.sz[dqzb.r][dqzb.c]=9;
}
void markPrint(Maze maze,zuobiao dqzb) {
maze.sz[dqzb.r][dqzb.c]=4;
}
zuobiao nextPos(zuobiao dqzb, int Dir) {
zuobiao xzb;
switch (Dir) {
case 1:
xzb.r=dqzb.r;
xzb.c=dqzb.c+1;
break;
case 2:
xzb.r=dqzb.r+1;
xzb.c=dqzb.c;
break;
case 3:
xzb.r=dqzb.r;
xzb.c=dqzb.c-1;
break;
case 4:
xzb.r=dqzb.r-1;
xzb.c=dqzb.c;
break;
}
return xzb;
}
int mazePath(Maze maze, zuobiao start, zuobiao end)
{
SqStack *s = (SqStack *)malloc(sizeof(SqStack));
initStack(s);
zuobiao dqzb = start; // �趨 "��ǰλ�� "Ϊ"���λ�� "
lujing e;
int curstep = 1; // ̽����һ��
do {
if (pass(maze,dqzb)) { // ��ǰλ�ÿ�ͨ��������δ���ߵ�����ͨ����
footPrint(maze,dqzb); // �����㼣
e.di =1;
e.ord = curstep;
e.seat= dqzb;
push(s,e); // ����·��
if (dqzb.r == end.r && dqzb.c==end.c)
return 0; // �����յ㣨���ڣ�
dqzb = nextPos(dqzb, 1); // ��һλ���ǵ�ǰλ�õĶ���
curstep++; // ̽����һ��
} else { // ��ǰλ�ò���ͨ��
if (!isEmpty(s)) {
pop(s,&e);
while (e.di==4 && !isEmpty(s)) {
markPrint(maze,e.seat);
pop(s,&e); // ���²���ͨ���ı�ǣ����˻�һ��
}
if (e.di<4) {
e.di++; // ����һ������̽��
push(s, e);
dqzb = nextPos(e.seat, e.di); // ��ǰλ����Ϊ�·�������ڿ�
}
}
}
} while (!isEmpty(s) );
return -1;
}
void main()
{
printf(" *---- ���Թ���� ��----*\n\n");
printf("--- �Թ�������ʾ :��˵���� 0 ��ʾǽ�� 1 ��ʾ����ͨ���� ");
printf("\n");
Maze maze; //���� maze
maze.sz[0][0]= 0;maze.sz[0][1]= 0;maze.sz[0][2]= 0;maze.sz[0][3]= 0;maze.sz[0][4]=
0;maze.sz[0][5]= 0;maze.sz[0][6]= 0;maze.sz[0][7]= 0;maze.sz[0][8]= 0;maze.sz[0][9]= 0;
maze.sz[1][0]= 0;maze.sz[1][1]= 1;maze.sz[1][2]= 1;maze.sz[1][3]= 0;maze.sz[1][4]=
1;maze.sz[1][5]= 1;maze.sz[1][6]= 1;maze.sz[1][7]= 0;maze.sz[1][8]= 1;maze.sz[1][9]= 0;
maze.sz[2][0]= 0;maze.sz[2][1]= 1;maze.sz[2][2]= 1;maze.sz[2][3]= 0;maze.sz[2][4]=
1;maze.sz[2][5]= 1;maze.sz[2][6]= 1;maze.sz[2][7]= 0;maze.sz[2][8]= 1;maze.sz[2][9]= 0;
maze.sz[3][0]= 0;maze.sz[3][1]= 1;maze.sz[3][2]= 1;maze.sz[3][3]= 1;maze.sz[3][4]=
1;maze.sz[3][5]= 0;maze.sz[3][6]= 0;maze.sz[3][7]= 1;maze.sz[3][8]= 1;maze.sz[3][9]= 0;
maze.sz[4][0]= 0;maze.sz[4][1]= 1;maze.sz[4][2]= 0;maze.sz[4][3]= 0;maze.sz[4][4]=
0;maze.sz[4][5]= 1;maze.sz[4][6]= 1;maze.sz[4][7]= 1;maze.sz[4][8]= 1;maze.sz[4][9]= 0;
maze.sz[5][0]= 0;maze.sz[5][1]= 1;maze.sz[5][2]= 1;maze.sz[5][3]= 1;maze.sz[5][4]=
0;maze.sz[5][5]= 1;maze.sz[5][6]= 1;maze.sz[5][7]= 0;maze.sz[5][8]= 1;maze.sz[5][9]= 0;
maze.sz[6][0]= 0;maze.sz[6][1]= 1;maze.sz[6][2]= 0;maze.sz[6][3]= 1;maze.sz[6][4]=
1;maze.sz[6][5]= 1;maze.sz[6][6]= 0;maze.sz[6][7]= 1;maze.sz[6][8]= 1;maze.sz[6][9]= 0;
maze.sz[7][0]= 0;maze.sz[7][1]= 1;maze.sz[7][2]= 0;maze.sz[7][3]= 0;maze.sz[7][4]=
0;maze.sz[7][5]= 1;maze.sz[7][6]= 0;maze.sz[7][7]= 0;maze.sz[7][8]= 1;maze.sz[7][9]= 0;
maze.sz[8][0]= 0;maze.sz[8][1]= 0;maze.sz[8][2]= 1;maze.sz[8][3]= 1;maze.sz[8][4]=
1;maze.sz[8][5]= 1;maze.sz[8][6]= 1;maze.sz[8][7]= 1;maze.sz[8][8]= 1;maze.sz[8][9]= 0;
maze.sz[9][0]= 0;maze.sz[9][1]= 0;maze.sz[9][2]= 0;maze.sz[9][3]= 0;maze.sz[9][4]=
0;maze.sz[9][5]= 0;maze.sz[9][6]= 0;maze.sz[9][7]= 0;maze.sz[9][8]= 0;maze.sz[9][9]= 0;
int i,j,sum;
for (i = 0; i < 10; i++) {
for (j = 0; j < 10; j++)
{
printf("%4d",maze.sz[i][j]);
sum++;
}
if(sum%10==0)
printf("\n");
}
printf("\n");
printf("--- ������ 1 ���·��ͼ :");
int a;
scanf("%d",&a);
if(a==1)
{
zuobiao rukou,chukou;
rukou.r=1;
rukou.c=1;
chukou.r=8;
chukou.c=8;
mazePath(maze,rukou,chukou);
printf("\n");
printf("--- ͼ��������ʾ :��˵���� 0 ��ʾǽ�� 1 ��ʾ����ͨ���� 4 ��ʾ�߲�ͨ�� 9 ��ʾ���ߵ�·���� \n");
for (i = 0; i < 10; i++) {
for (j = 0; j < 10; j++)
{
printf("%4d",maze.sz[i][j]);
sum++;
}
if(sum%10==0)
printf("\n");
}
}
}
