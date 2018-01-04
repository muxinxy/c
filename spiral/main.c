#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10]={{0}};
    int i=0,j=0,k=0,n,num=1,x=0,y=0;
    printf("Please input n(1-10):");
    scanf("%d",&n);
    y=n*(n+1)/2;
    for(i=0;i<=n/2&&(num<=y);i++)
    {
        for(j=i;j<=n-i-1-i&&(num<=y);j++)
            a[i][j]=num++;
        for(k=i+1;k<n-i-1&&(num<=y);k++)
            a[k][n-i-1-k]=num++;
            a[n-1][0]=2*n-1;
            x++;
            if(i==0)num++;
        for(k=n-i-1-x;k>i&&(num<=y);k--)
            a[k][i]=num++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(a[i][j]!=0)
                printf("%3d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
