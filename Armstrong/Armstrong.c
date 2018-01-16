#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n[100]={0};

int a_size(int a)
{
    int i,j=1;
    for(i=1;i<a&&a/i>=10;i*=10)
    {
        j++;
    }
    return j;
}

void print(int a)
{
    int i,j=0,x,y,flag;
    y=a_size(a);
    x=a%10;
    if(x==0)y--;
    for(i=1;i<=y;i++)
    {
        flag=0;
        printf("n=%d:",i);
        if(i==1)
        {
            printf("0  ");
            flag=1;
        }
        while(a_size(n[j])==i)
        {
            if(n[j]!=0&&n[j]!=255)
            {
                printf("%d  ",n[j]);
                flag=1;
            }
            j++;
        }
        if(flag==0)printf("No number!");
        if(i!=y)printf("\n");
    }
}

void as(int a)
{
    int size,i,j,k=0,sum,x;
    for(i=0;i<a;i++)
    {
        size=a_size(i);
        sum=0;
        x=i;
        for(j=size;j>0;j--)
        {
            sum+=(int)round(pow(x/((int)round(pow(10,j-1))),size));
            x-=(x/((int)round(pow(10,j-1))))*((int)round(pow(10,j-1)));
        }
        if(sum==i)n[k++]=i;
    }
}

int main()
{
    int a=0;
    printf("Please input a positive number:");
    scanf("%d",&a);
    as(a);
    print(a);
    return 0;
}
