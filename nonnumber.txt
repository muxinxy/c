#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int number[100];

int fun(char *a)
{
    int i,j=0,k=0,l,s=strlen(a),b[100],n=0;
    for(i=0;i<s;i++)
    {
        if(a[i]>=48&&a[i]<=57)
        {
            b[k]=a[i]-'0';
            k++;
            if(a[i+1]<48||a[i+1]>57)
            {
                for(l=k;l>0;l--)
                {
                    n+=b[k-l]*(int)round(pow(10,l-1));
                }
                number[j]=n;
                j++;
            }
        }
        else
        {
            n=0;
            k=0;
        }
    }
    return (j);
}

int main()
{
    int sum,i;
    char str[100],*a;
    printf("Please input string:");
    gets(str);
    a=str;
    sum=fun(a);
    printf("Sum=%d\n",sum);
    for(i=0;i<sum;i++)
    {
        printf("%d\t",number[i]);
    }
    return 0;
}
