#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000000

int main()
{
    int n,i,j=0,k;
    for(n=1;n<=N;n++){
        k=sqrt(n);
        if(n==2)j=1;
        else {
                for(i=2;i<=k;i++)
                if(n%i==0)break;
                if(i>k&&n>2)j++;
            }

    }
    printf("%d",j);
    return 0;
}
