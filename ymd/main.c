#include <stdio.h>
#include <stdlib.h>

int years(int year)//判断闰年
{
    if(year%400==0||(year%4==0&&year%100!=0))return(29);
    else return(28);
}

int main()//主函数，输入年月日，判断其为这一年的第几天
{
    int y,m,d,sum=0,i;
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30};//定义一个每月天数的数组
    printf("Please input year,month,day:");
    scanf("%d-%d-%d",&y,&m,&d);//输入年月日
    month[2]=years(y);//调用闰年函数，对2月天数重新赋值
    for(i=0;i<m;i++)
    {
        sum=sum+month[i];
    }
    sum=sum+d;//计算天数
    printf("%d-%d-%d is the No.%d day of %d",y,m,d,sum,y);
    return 0;
}
