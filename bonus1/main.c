#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double I,sum;
    int i;
    printf("Please input the interest of this month:");
    scanf("%lf",&I);
    if(I<1000000)i=ceil(I/100000);
    switch(i)
    {
        case 1:sum=I*10.0/100;break;
        case 2:sum=100000*10.0/100+(I-100000)*7.5/100;break;
        case 3:
        case 4:sum=100000*10.0/100+100000*7.5/100+(I-200000)*5.0/100;break;
        case 5:
        case 6:sum=100000*10.0/100+100000*7.5/100+200000*5.0/100+(I-400000)*3.0/100;break;
        case 7:
        case 8:
        case 9:
        case 10:sum=100000*10.0/100+100000*7.5/100+200000*5.0/100+200000*3.0/100+(I-600000)*1.5/100;break;
        default:sum=100000*10.0/100+100000*7.5/100+200000*5.0/100+200000*3.0/100+400000*1.5/100+(I-1000000)*1.0/100;
    }
    printf("Bonus=%.2lf",sum);
    return 0;
}
