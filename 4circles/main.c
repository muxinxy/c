#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define a 2
#define b 2
#define r 1

int main()
{
    int h=0;
    double x,y,d;
    printf("Please input x,y:");
    scanf("%lf,%lf",&x,&y);
    x=fabs(x);
    y=fabs(y);
    d=sqrt(pow((x-a),2)+pow((y-b),2));
    if(d-r<pow(10,-6))h=10;
    printf("h=%dm",h);
    return 0;
}
