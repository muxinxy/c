#include <stdio.h>
#include <stdlib.h>

int fun4(int a,int b)
{
    int result,v3;
    if(a<=0)
        return 0;
    result=b;
    if(a!=1)
    {
        v3=fun4(a-1,b)+b;
        result=v3+fun4(a-2,b);
    }
    return result;
}

int main()
{
    int result;
    result=fun4(7,3);
    printf("%d\n",result);
    return 0;
}
