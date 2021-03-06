#include <stdio.h>
int is_int(char *s)//判断s中是否为整数,如果是返回1,否则返回0
{
    char* p =s;//p指向s
    if(*p=='+'||*p=='-')//如果第一个字符为符号,则从第二个开始遍历
        p++;
    while(*p)//遍历字符串
    {
        if(*p<'0'||*p>'9') return 0;//出现非法字符,返回0,表示不是整数
        p++;//判断下一个字符
    }
    return 1;//所有都是合法字符,返回1,表示为整数
}
int main()
{
    char s[1000];
    gets(s);//读取输入,存到s中
    if(is_int(s))//判断并输出结果
        printf ("YES\n",s);
    else
        printf ("NO\n",s);
    return 0;
}
