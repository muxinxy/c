#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,num1,num2;
    printf("请输入整数（a b）:");
    scanf("%d %d",&num1,&num2);
    a=num1;
    b=num2;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    printf("最大公约数：%d\n",a);
    a=num1*num2/a;
    printf("最小公倍数：%d",a);
    return 0;
}
