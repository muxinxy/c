#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
int scr[22][50], q=14, w=30, ban=20, score=1, sx=-1 , zy=-1 ,speed=1, chang=30;
void moveqiu(void);
void penzhuangqiu(void);
void print(void);
void menu(void);


int main(void)
{
int i=0,j=0;
menu();
for(;j<50;j++)
scr[i][j]=4;
j=0;i=1;
;for(;i<3;i++)
for(j=2;j<48;j++)
scr[i][j]=3;
//��������שͷλ��
scr[q][w]=2;
while(1)
{
for(j=0;j<20;j++)//����λ�ù�0
scr[21][ban+j]=0;
if(kbhit())//���ư���ƶ�
switch(getch())
{
case'a':case'A':if(ban>1&&ban<=29) ban--;
break;
case'd':case'D':if(ban>0&&ban<=28) ban++;
break;
case'w':case'W':getch();break;//��ͣ��
}
for(j=0;j<20;j++)//������λ��Ϊ1
scr[21][ban+j]=1;
penzhuangqiu();
moveqiu();
print();


}

return 0;
}


void penzhuangqiu(void)
{
int b;
b=0;
if(zy==1)//�����ĸ�if�������ײש�����ı�����˶�����
if(scr[q][w+1]==3||w+1==49)
{
scr[q][w+1]=0;
zy=-zy;
b=1;
}
if(zy==-1)//�ж��˶����з���
if(scr[q][w-1]==3||w-1==0)
{
scr[q][w-1]=0;
zy=-zy;
b=1;//����ȷ���Ƿ��ô��������µķ���
}


if(sx==1)
if(scr[q-1][w]==3||q-1==0)
{
scr[q-1][w]=0;
sx=-sx;
b=1;
}
if(sx==-1)
if(scr[q+1][w]==3||q+1==21)
{
if(scr[q+1][w]==3)
{scr[q+1][w]=0;
sx=-sx;
b=1;
}
if(q+1==21)
{if(scr[q+1][w]==1)
sx=-sx;
else
{
printf("lose!!!!!!�˳���Ϸ");
if(getch())
main();
}
}
}
if(b==0)//б��ש��
{
if(zy==1&&sx==1)
if(scr[q-1][w+1]==3)
{
scr[q-1][w+1]=0;
zy=-zy;
sx=-sx;
}


if(zy==-1&&sx==1)
if(scr[q-1][w-1]==3)
{
scr[q-1][w-1]=0;
zy=-zy;
sx=-sx;
}


if(zy==1&&sx==-1)
if(scr[q+1][w+1]==3)
{
scr[q+1][w+1]=0;
zy=-zy;
sx=-sx;
}


if(zy==-1&&sx==-1)
if(scr[q+1][w-1]==3)
{
scr[q+1][w-1]=0;
zy=-zy;
sx=-sx;
}//бש���
}
}


void moveqiu(void)
{
scr[q][w]=0;//ʹԭ������λ��Ϊ0,�������µ���λ��
if(sx==1&&zy==1)
{
q--;w++;
}
if(sx==1&&zy==-1)
{
q--;w--;
}
if(sx==-1&&zy==1)
{
q++;w++;
}
if(sx==-1&&zy==-1)
{
q++;w--;
}
scr[q][w]=2;
}


void print(void)
{
int i, j;
system("cls");
for(i=0;i<22;i++)
{
for(j=0;j<50;j++)
{
if(scr[i][j]==0)printf(" ");
if(scr[i][j]==1)printf("\3");
if(scr[i][j]==2)printf("\4");
if(scr[i][j]==3)printf("\5");
if(scr[i][j]==4)printf("_");
if(j==49)
printf("|\n");
}
}
}


void menu(void)
{
q=14, w=30, ban=20, score=1, sx=-1 , zy=-1 ,speed=1, chang=30;memset(scr,0, sizeof(int)*1100);
system("cls");
printf("A����D���ң�W��ͣ\n��ʼ��Ϸ�������\n ");
if(getch()) printf("aaaaaa");
}
