#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[21];//定义字符串
    printf("请输入n个字符组成的字符串（1<=n<=20，以空格分隔）：");
    gets(str);//输入字符串
    int i,len=strlen(str);//定义变量序数i和字符串长度len
    for (i=0;i<len&&str[i]!='\n';i++)//循环体开始
    {
        if (str[i]!=32)//判断字符是否为空格
            {
                if ((str[i]>='A'&&str[i]<='V')||(str[i]>='a'&&str[i]<='v'))//判断字母位置
                    str[i]=str[i]+4;
                else
                    str[i]=str[i]-22;

            }
        else
            str[i]=32;
    }
    printf("密码为：");
    puts(str);//输出转换后的字符串
    return 0;
}
