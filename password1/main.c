#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c;//定义变量c
    int i=1;
    printf("请输入n个字符组成的字符串（1<=n<=20，以空格分隔）：");
    c=getchar();//初始化变量c
    printf("密码为：");
    while (c!='\n'&&i<=20)//判断字符是否为回车
    {
        if (c!=32)//判断字符是否为空格
            {
                if ((c>='A'&&c<='V')||(c>='a'&&c<='v'))//判断字母位置
                    c=c+4;
                else
                    c=c-22;

            }
        else
            c=32;
        putchar(c);//输出字符
        c=getchar();//将下一个字符赋值给变量c
        i++;
    }
    return 0;
}
