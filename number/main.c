#include <stdio.h>
int main()
{
    char a[1000];
    int i,f=1;
    gets(a);
    for(i=0;a[i];i++)
    {
        if(!(a[i]>='0'&&a[i]<='9'))
        {
            f=0;
            break;
        }
    }
    if(f)
        printf("Yes");
    else
        printf("No");
    return 0;
}
