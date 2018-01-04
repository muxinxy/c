#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void local(double w)
{
    double price=10;
    if(w>1)price+=ceil(w-1)*3;
    printf("Price:%.2lf",price);
}

void near(double w)
{
    double price=10;
    if(w>1)price+=ceil(w-1)*4;
    printf("Price:%.2lf",price);
}

void other(double w,int a)
{
    double price=15;
    if(w>1)
        switch(a)
        {
        case 2:price+=ceil(w-1)*5;break;
        case 3:price+=ceil(w-1)*6.5;break;
        case 4:price+=ceil(w-1)*10;break;
        }
    printf("Price:%.2lf",price);
}

int main()
{
    int a;
    double w;
    scanf("%d,%lf",&a,&w);
    if(a>=0&&a<=4&&w>=0)
    {
        switch(a)
        {
        case 0:local(w);break;
        case 1:near(w);break;
        case 2:
        case 3:
        case 4:other(w,a);break;
        }
    }
    else if((a<0||a>4)&&w>=0)printf("Error in area\nPrice:0.00");
    else if(w<0)printf("Error in weight\nPrice:0.00");
    else printf("Error in area and weight\nPrice:0.00");
    return 0;
}
