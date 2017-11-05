#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000000

int main()
{
    int n,i,j=0;
    for(n=1;n<=N;n++){
        for(i=2;i<=sqrt(n);i++)
            if(n%i==0)break;
        if(i>sqrt(n))j++;
    }
    printf("%d",j);
    return 0;
}
