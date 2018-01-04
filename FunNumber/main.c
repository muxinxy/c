#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j,x=1,n=0;
    for(i=1;i<=10000;i*=10)
    {
        for(j=i;j<i*10;j++)
            if(((j*j)%(int)round(pow(10,x)))==j)
            {
                printf("%d ",j);
                n++;
            }
        x++;
    }
    printf("\n%d",n);
    return 0;
}
