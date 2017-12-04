#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000000

double f1(double x)
{
    return(sin(x));
}
double f2(double x)
{
    return(cos(x));
}
double f3(double x)
{
    return(exp(x));
}

double integral(double (*p)(double),double a,double b)
{
    int i;
    double m=(b-a)/(2*N);
    double sum=0;
    for(i=1;i<=N;i++)
    {
        sum+=((*p)(a+m*(2*i-1)))*(2*m);
    }
    return(sum);
}

int main()
{
    int select;
    double a,b,result;
    while(select!=0)
    {
        printf("1.sin(x)\t2.cos(x)\n3.exp(x)\t0.exit\n");
        printf("Please select a number:");
        scanf("%d",&select);
        if(select==1||select==2||select==3)
        {
            printf("Please input a and b:");
            scanf("%lf,%lf",&a,&b);
            switch(select)
            {
                case 1:result=integral(f1,a,b);break;
                case 2:result=integral(f2,a,b);break;
                case 3:result=integral(f3,a,b);break;
            }
            printf("Result is %lf\n",result);
        }
        else if(select!=0)printf("Error\n");
    }
    return 0;
}
