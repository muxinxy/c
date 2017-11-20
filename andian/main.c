#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int a[3][4]={{1,2,3,13},{5,6,14,8},{9,10,11,12}};
    int i,j,k,m,n;
    for(i=0;i<3;i++)
    {
        m=a[i][0];
        k=0;
        for(j=0;j<3;j++)
        {
            if(a[i][j+1]>m)
            {
                m=a[i][j+1];
                k=j+1;
            }
        }
        j=k;
        n=a[0][j];
        k=0;
        for(i=0;i<2;i++)
        {
            if(a[i+1][j]<n)
            {
                n=a[i+1][j];
                k=i+1;
            }
        }
        if(m==n)break;
    }
    if(m==n)printf("鞍点是：%d，在第%d行、第%d列",m,k+1,j+1);
    else printf("没有鞍点");
    return 0;
}
