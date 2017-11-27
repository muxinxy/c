#include <stdio.h>
#include <stdlib.h>
#define M 3

void kill(int a[41],int *p[41])
{

}

int main()
{
    int i,n,a[41];
    int *p[41];
    for(i=0;i<41;i++)
    {
        a[i]=i+1;
    }
    for(i=0;i<41;i++)
    {
        p[i]=&a[i];
    }
    kill(a,p);
    return 0;
}
