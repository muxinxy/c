#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, index, remain, delete[41], flag[41] = {0};
    int n=41,p=3;
    remain = n;
    index = 0;
    while (remain >= 1)
    {
        for (i = 0; i < n; i ++)
        {
            if (flag[i] == 0)
            {
                index ++;
                if (index == p)
                {
                    flag[i] = 1;
                    index = 0;
                    delete[remain - 1] = i + 1;
                    remain --;
                }
            }
        }
    }
    for (i = n - 1; i >= 0; i --)
    {
        if ((i-1)%10==0)
        {
          printf("%d\n", delete[i]);
        }
        else
        {
          printf("%d\t", delete[i]);
        }
    }
    return 0;
}
