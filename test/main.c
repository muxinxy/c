#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num(int n,int m)
{
    int b;
    b=(int)round(pow(10,m));
    return (n%b);
}
int main()
{
    int a[100]={0};
    int cnt=0,i,j=0,m=0,c;
    int n;
    for (i=1;i<10000;i++)
    {
        m=0;
        n=i*i;
        c=i;
        while (c>=10)
        {
            c=c/10;
            m++;
        }
        if (i==num(n,m+1))
        {
            cnt++;
            a[j]=i;
            j++;
        }
    }
    printf("They are:");
    for (i=0;i<j;i++)
        printf("%d ",a[i]);
    printf("\nIn total:%d",cnt);
    return 0;
}
