#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include <windows.h>
void a0(int x,int p[])//����x��ÿһλ�����浽p��,���ڰ�����//
{
	int i,k;
	for(i=0,k=1000;i<4;i++)
	{
		p[i]=x/k;
		x=x%k;
		k=k/10;
	}
}
void a1(int x,int y)//����1//
{
	if(x>y)printf("��������Ȳ���������\n");
		if(x<y)printf("��������Ȳ�������С\n");
}
void a2(int x)//������ �ж���ż��//
{
	if(x%2==1)printf("������������\n");
	if(x%2==0)printf("��������ż��\n");
}
int a3(int x)//������ �ж��Ƿ�������//
{
	int i;
	for(i=2;i<=x-1;i++)
	if(x%i==0)break;
	if(i<x)return(0);
	else return(1);
}
void a4(int x,int y)//������ ���x �� y������
{
	int i;
	for(i=x;i<=y;i++)
	{
		if(a3(i)==1)printf("%d  ",i);
	}
}
void a5(int x,int y)//������ �жϸ�λ��������
{
	int m[4],n[4],i;
	char t[6];
	a0(x,m);a0(y,n);
	for(i=0;i<4;i++)
	{if(m[i]==n[i])t[i]='R';
	else t[i]='E';}
    puts(t);
	printf("\n");

}
void a6(int x,int y)//������ ������е�����//
{

	int m[4],n[4],i,j,l=0,u,k;
	int t[6];
	a0(x,m);a0(y,n);
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	{if(m[i]==n[j])
	{
		k=1;
		for(u=0;u<l;u++)
		if(t[u]==m[i])k=0;
	if(k){t[l]=m[i];l++;break;}}
	}
	}
	if(l!=0)
{
	printf("���е����У�");
   for(i=0;i<l;i++)
   {
   	printf("  %d",t[i]);
   }
   printf("\n");
}
else printf("û�в��е���\n");
}
void a7(int x,int y)//������ ���ָ��λ��������
{
int l[4];
a0(y,l)	;
printf("��%dλ����%d\n",x,l[x-1]);
}
void a8(int x)//������ �����λ��֮��//
{
	int i,l[4];
a0(x,l)	;
i=l[0]+l[2]+l[3]+l[1];
printf("��λ��֮��Ϊ��%d\n",i);
}

void caidan()  //�˵�ҳ��
{
   printf("     *****Ȥζ����*******\n****(G)����      (H)����*****\n****(Q)���¿�ʼ  (E)�뿪*****\n");
}
void huanying()//��Ϸ��ʼ֮ǰ�Ļ�ӭ��
{
	printf("--------------------��ӭ������Ϸ!--------------------\n        ���������4λ���������������£�\n        ������ߴβ�������\n        ÿ�οɻ��һ��������\n----------------------------------------------------\n��Y��ʼ��Ϸ \n");
}
void changyong(int y,int x)//���õ�һ�仰��Ϊ�˷��㣬����Ϊ����
{
	printf("���ϴβµ���Ϊ%d\n��ѡ���˰���%d���۳���ǰ�����ٷ�֮ʮ\n",y,x);
}
int main()  //������
{ int i,r,x,z,sum=100,a,b,g,m=0;//���������ַ�
char n,f,y;
   srand(time(NULL));
    r=rand()%9000+1000;//���������
  huanying();
  scanf("%c",&y);
  getchar();
if(y=='y'||'Y')
{for(i=1;i<8;)//����forѭ�����ﵽֻ�ܻش��ߴε�Ч��
   {
  	caidan();
  	printf("��ѡ����Ŀ��");
  	scanf("%c",&n);
  	fflush(stdin);
  	if(n=='g'||n=='G')//����G����g��ʼ����
  	{
		printf("������һ����λ��:");
	  scanf("%d",&x);//���������������
	  getchar();
	  if(x<1000||x>9999)
         {printf("������1000-9999�ڵ������������벻����Ҫ��\n");i=i-1; }//�����ֲ��ڷ�Χ֮���ǣ����۳���������
  	  if(x==r)
   {
   system("cls");
   printf("��ϲ�������ȷ����ǰ�÷֣�%d\n",sum);
   printf("             **            **        \n");
     printf("        *        *      *       *    \n");
     printf("       *            *             *  \n");
     printf("      *        �й������ѧ       * \n");
     printf("      *        ��һ34�ڵ�9��      * \n");
     printf("      *        �����������       * \n");
     printf("      *               ����        * \n");
     printf("       *                         *  \n");
     printf("        *                       *   \n");
     printf("         *                     *    \n");
     printf("           *                 *      \n");
     printf("             *             *        \n");
     printf("               *         *          \n");
     printf("                  *   *             \n");
     printf("                    *               \n");
	 while(999){
		for(z=0;z<199999999;z++);
		system("color d");
		for(z=0;z<199999999;z++);
		system("color a");
		for(z=0;z<199999999;z++);
		system("color c");
		for(z=0;z<199999999;z++);
		system("color b");
		for(z=0;z<199999999;z++);
		system("color f");
		for(z=0;z<199999999;z++);
		system("color e");
	}
		   }//����Ҳ����ɹ�������÷֣�

      if(i==7)
         {printf("��Ǹ����Ĳ���������ʹ���꣬��Ϸ����"); }//�����������꣬��Ϸ����
      else printf("%d����ȷ����ǰ�÷�%d,ʣ��%d�λ���,����԰�hѰ�����\n",x,sum,7-i);
      i++;//ÿ��һ�������������һ��
  	}
    else if(n=='h'||n=='H')
    {
    	printf("ÿ��ʹ�ð������ٵ�ǰ�����İٷ�֮ʮ\n");
        printf("1. �ж��������ֱȲ��������ִ���С��\n");
        printf("2. �ж�����������ż����\n");
        printf("3. �ж��ǲ�����������������������ָ����Χ�ڵ�������\n");
        printf("4. ��λ���ֶ�Ӧλ�������������R����ȷ��E�����\n");
        printf("5. �ж������µ�������ȷ������ʲô��\n");
        printf("6. �������ĳλ������ʲô��\n");
        printf("7. ���4λ����֮�͡�\n");
        printf("8. �������β�������ʾ�������\n");
        printf("9. ��������ζ�����\n");
        printf("0. ��ʾ�������������������Լ��\n");
        printf("��ѡ������Ҫ�İ�����"); //����Ϊ9����������Ҹ������������ʹ�ð���
        scanf("%c",&f);
        fflush(stdin);
if(f=='1'){changyong(x,1);a1(x,r);sum=sum*0.9;}//����һ
if(f=='2'){changyong(x,2);a2(r);sum=sum*0.9;}//������
if(f=='3')
{
	changyong(x,3);
	i=a3(r);
	if(i==0)printf("�ⲻ��һ������\n");
	if(i==1)
	{
		printf("����һ������\n");
		printf("�������ѯ����\n");scanf("%d",&a);getchar();
		printf("�������ѯ����\n");scanf("%d",&b);getchar();
		if(a<b&&x>=a){a4(a,b);printf("\n");}
		else printf("�޷�ʶ����������ȷ�ķ�Χ\n");//��������
	}
	sum=sum*0.9;
}   //������
if(f=='4')
  {
   changyong(x,4);a5(x,r);sum=sum*0.9;
  } //������
if(f=='5')
  {
   changyong(x,5);a6(x,r);sum=sum*0.9;
  }//������
if(f=='6')
  {
   if(m==0)
     {changyong(x,6);
      printf("�������ѯ��λ��:");
      scanf("%d",&g);
      if(g>0&&g<5)
        {a7(g,r);sum=sum*0.9;m=1;}
      else printf("�������ĵĲ�ѯ\n");}
   else printf("�ð���ֻ��ʹ��һ��\n");
  }//������
if(f=='7')
  {
    changyong(x,7);a8(r);sum=sum*0.9;
  }//������
if(f=='8')
  {
	printf("�����������������Ϊ��%d\n",r);i=7;
  }//������
if(f=='9')
  {
	printf("����һ�����ģ�����Ŭ��\n    * *   * *\n   *   * *   *\n   *    *    *\n    *       *\n     *     *\n      *   *\n        *\n");
  }//������
 if(f=='0')
 	{
	 	void gongyueshu(int a,int b);
	 	gongyueshu(x,r);
	 }
    }
    else if(n=='Q'||n=='q'){i=1;sum=100;} //���²���
    else if(n=='E'||n=='e')exit(0);//�رճ���
    else printf("��������ȷ��ָ��\n");//�����ַ�����ʱ�������
    printf("\n\n\n");
  }
}
  return 0;
}



	void  gongyueshu( int  a, int  b )
{
    int c;
	while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    printf("%d",a);

}
