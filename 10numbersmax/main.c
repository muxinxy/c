#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    int i,Max;
    printf(" ������10��������\n");
    for (i=0;i<10;i++)
        scanf("%d",&a[i]);
    for (i=0;i<10;i++)
        if (Max<a[i])
            Max=a[i];
    printf("�������ǣ�%d\n",Max);
    return 0;
}
