#include <stdio.h>
int func4(int a1,int a2,int a3)
{
    int result=0;
    result=(a3-a2)/2+a3;
    if(a1>result)
        result=result+func4(a1,a2,result-1);
    else if(a1<result)
        result=result+func4(a1,result+1,a3);
    return result;
}
int main()
{
    int value=0;
    for(;value<=14;value++)
    {
        if(func4(value,0,14)==11)
            printf("the value is %d\n",value);
    }
    return 0;
}
