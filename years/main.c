#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,year;//定义换行控制变量i和年份year
    i=0;
    year=2000;//年份初始值
    printf("2000年-2200年的闰年为：\n");
    while (year<=2200)//循环体开始
    {
        if((year%4==0&&year%100!=0)||(year%400==0))//判断是否是闰年
        {
            printf("%d ",year);//输出是闰年的年份
            i++;//计数已经输出的闰年数
            if(i%10==0)//判断是否已经输出十个年份
                printf("\n");//如果已经输出十个年份就换行，不到十个就不换行
        }
        year++;//年份加一，继续验证
    }
    printf("\n闰年数：%d",i);//输出总闰年数
    return 0;
}
