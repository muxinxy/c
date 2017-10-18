#include <stdio.h>

int main()
{
    int max(int x1,int x2,int x3);
    int a,b,c,d;
    scanf("%d,%d,%d",&a,&b,&c);
    d=max(a,b,c);
    printf("max=%d\n",d);
    return 0;
}
int max(int x1,int x2,int x3)
{
    int z;
    if(x1>x2&& x1>x3)z=x1;
    if(x2>x1&&x2>x3)z=x2;
    if(x3>x2&&x3>x1)z=x3;
    return(z);

}
