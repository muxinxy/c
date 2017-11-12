#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("Please input n(1<=n<=10):");
    scanf("%d",&n);
    if(n>=1&&n<=10)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i;j++)
                printf(" ");
            for(j=n-i+1;j<=n+i-1;j++)
                printf("*");
            printf("\n");
        }
        for(i=n+1;i<=2*n-1;i++)
        {
            for(j=1;j<=i-n;j++)
                printf(" ");
            for(j=i-n+1;j<=3*n-i-1;j++)
                printf("*");
            printf("\n");
        }
    }
    else printf("Error");
    return 0;
}
