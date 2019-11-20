#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,result;
    scanf("%d",&a);
    result=(a&0xf)*4;
    printf("%d\n",result);
    return 0;
}
