#include <stdio.h>
#include <stdlib.h>
#define N 10000

int main()
{
    int n,i,sum=0;
    for(n=6;n<=N;n++)
        {
            sum=0;
            for(i=1;i<=n/2;i++)
            {
                if(n%i==0)sum=sum+i;
            }
            if(sum==n)
            {
                if(n!=6)printf("\n%d its factors are ",n);
                else printf("%d its factors are ",n);
                for(i=1;i<=n/2;i++)
                {
                    if(n%i==0&&i!=n/2)printf("%d,",i);
                    else if(n%i==0&&i==n/2) printf("%d",i);
                }
            }
    }
    return 0;
}
