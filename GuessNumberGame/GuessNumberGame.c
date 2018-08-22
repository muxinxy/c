#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include <windows.h>
void a0(int x,int p[])//将数x的每一位数储存到p中,便于帮助四//
{
	int i,k;
	for(i=0,k=1000;i<4;i++)
	{
		p[i]=x/k;
		x=x%k;
		k=k/10;
	}
}
void a1(int x,int y)//帮助1//
{
	if(x>y)printf("输入的数比产生的数大\n");
		if(x<y)printf("输入的数比产生的数小\n");
}
void a2(int x)//帮助二 判断奇偶数//
{
	if(x%2==1)printf("产生数是奇数\n");
	if(x%2==0)printf("产生数是偶数\n");
}
int a3(int x)//帮助三 判断是否是素数//
{
	int i;
	for(i=2;i<=x-1;i++)
	if(x%i==0)break;
	if(i<x)return(0);
	else return(1);
}
void a4(int x,int y)//帮助四 输出x 到 y的素数
{
	int i;
	for(i=x;i<=y;i++)
	{
		if(a3(i)==1)printf("%d  ",i);
	}
}
void a5(int x,int y)//帮助五 判断各位数的正误
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
void a6(int x,int y)//帮助六 输出猜中的数字//
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
	printf("猜中的数有；");
   for(i=0;i<l;i++)
   {
   	printf("  %d",t[i]);
   }
   printf("\n");
}
else printf("没有猜中的数\n");
}
void a7(int x,int y)//帮助七 输出指定位数的数字
{
int l[4];
a0(y,l)	;
printf("第%d位数是%d\n",x,l[x-1]);
}
void a8(int x)//帮助八 输出四位数之和//
{
	int i,l[4];
a0(x,l)	;
i=l[0]+l[2]+l[3]+l[1];
printf("四位数之和为：%d\n",i);
}

void caidan()  //菜单页面
{
   printf("     *****趣味猜数*******\n****(G)猜数      (H)帮助*****\n****(Q)重新开始  (E)离开*****\n");
}
void huanying()//游戏开始之前的欢迎词
{
	printf("--------------------欢迎进入游戏!--------------------\n        计算机产生4位随机数，让玩家来猜；\n        玩家有七次猜数机会\n        每次可获得一个帮助；\n----------------------------------------------------\n按Y开始游戏 \n");
}
void changyong(int y,int x)//常用的一句话，为了方便，独立为函数
{
	printf("您上次猜的数为%d\n您选择了帮助%d，扣除当前分数百分之十\n",y,x);
}
int main()  //主函数
{ int i,r,x,z,sum=100,a,b,g,m=0;//定义所需字符
char n,f,y;
   srand(time(NULL));
    r=rand()%9000+1000;//产生随机数
  huanying();
  scanf("%c",&y);
  getchar();
if(y=='y'||'Y')
{for(i=1;i<8;)//利用for循环来达到只能回答七次的效果
   {
  	caidan();
  	printf("请选择项目：");
  	scanf("%c",&n);
  	fflush(stdin);
  	if(n=='g'||n=='G')//输入G或者g开始猜数
  	{
		printf("请输入一个四位数:");
	  scanf("%d",&x);//输入玩家所猜数字
	  getchar();
	  if(x<1000||x>9999)
         {printf("请输入1000-9999内的数，您的输入不符合要求。\n");i=i-1; }//当数字不在范围之内是，不扣除猜数机会
  	  if(x==r)
   {
   system("cls");
   printf("恭喜你猜数正确，当前得分：%d\n",sum);
   printf("             **            **        \n");
     printf("        *        *      *       *    \n");
     printf("       *            *             *  \n");
     printf("      *        中国海洋大学       * \n");
     printf("      *        周一34节第9组      * \n");
     printf("      *        姓名：李昊贤       * \n");
     printf("      *               曲政        * \n");
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
		   }//当玩家猜数成功，算出得分；

      if(i==7)
         {printf("抱歉，你的猜数次数已使用完，游戏结束"); }//猜数机会用完，游戏结束
      else printf("%d不正确，当前得分%d,剩余%d次机会,你可以按h寻求帮助\n",x,sum,7-i);
      i++;//每猜一次数，机会减少一次
  	}
    else if(n=='h'||n=='H')
    {
    	printf("每次使用帮助减少当前分数的百分之十\n");
        printf("1. 判断输入数字比产生的数字大还是小。\n");
        printf("2. 判断是奇数还是偶数。\n");
        printf("3. 判断是不是素数，如果是素数，输出指定范围内的素数。\n");
        printf("4. 各位数字对应位置正误情况，以R表正确，E表错误。\n");
        printf("5. 判断你所猜的数中正确数字是什么。\n");
        printf("6. 请求输出某位数字是什么。\n");
        printf("7. 输出4位数字之和。\n");
        printf("8. 放弃本次猜数，显示随机数。\n");
        printf("9. 开启你的任督二脉\n");
        printf("0. 显示您输入的数与该数的最大公约数\n");
        printf("请选择你想要的帮助："); //以上为9个帮助，玩家根据自身情况，使用帮助
        scanf("%c",&f);
        fflush(stdin);
if(f=='1'){changyong(x,1);a1(x,r);sum=sum*0.9;}//帮助一
if(f=='2'){changyong(x,2);a2(r);sum=sum*0.9;}//帮助二
if(f=='3')
{
	changyong(x,3);
	i=a3(r);
	if(i==0)printf("这不是一个素数\n");
	if(i==1)
	{
		printf("这是一个素数\n");
		printf("请输入查询下限\n");scanf("%d",&a);getchar();
		printf("请输入查询上限\n");scanf("%d",&b);getchar();
		if(a<b&&x>=a){a4(a,b);printf("\n");}
		else printf("无法识别，请输入正确的范围\n");//错误输入
	}
	sum=sum*0.9;
}   //帮助三
if(f=='4')
  {
   changyong(x,4);a5(x,r);sum=sum*0.9;
  } //帮助四
if(f=='5')
  {
   changyong(x,5);a6(x,r);sum=sum*0.9;
  }//帮助五
if(f=='6')
  {
   if(m==0)
     {changyong(x,6);
      printf("请输入查询的位数:");
      scanf("%d",&g);
      if(g>0&&g<5)
        {a7(g,r);sum=sum*0.9;m=1;}
      else printf("不正当的的查询\n");}
   else printf("该帮助只能使用一次\n");
  }//帮助六
if(f=='7')
  {
    changyong(x,7);a8(r);sum=sum*0.9;
  }//帮助七
if(f=='8')
  {
	printf("您放弃猜数，随机数为：%d\n",r);i=7;
  }//帮助八
if(f=='9')
  {
	printf("送你一个爱心，继续努力\n    * *   * *\n   *   * *   *\n   *    *    *\n    *       *\n     *     *\n      *   *\n        *\n");
  }//帮助九
 if(f=='0')
 	{
	 	void gongyueshu(int a,int b);
	 	gongyueshu(x,r);
	 }
    }
    else if(n=='Q'||n=='q'){i=1;sum=100;} //重新猜数
    else if(n=='E'||n=='e')exit(0);//关闭程序
    else printf("请输入正确的指令\n");//输入字符错误时提醒玩家
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
