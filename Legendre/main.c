#include <stdio.h>
#include <stdlib.h>

double p(int a,double b)//定义函数计算勒让德多项式
{
    double c;
    if(a==0)c=1;
    else if(a==1)c=b;
    else c=((2*a-1)*b-p(a-1,b)-(a-1)*p(a-2,b))/a;
    return c;

}

int main()
{
    int n;
    double x,y;
    printf("Please input n,x:");
    scanf("%d,%lf",&n,&x);//输入n和x
    y=p(n,x);//调用函数计算勒让德多项式的值
    printf("The value of Legendre is %lf",y);
    return 0;
}
