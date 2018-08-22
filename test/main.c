#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k,m,n;
    scanf("%d %d",&m,&n);
    for (i = m; i <= n; i += 1)  //偶数必不是素数，从101开始，i每循环一次加二
    {
        k = sqrt(i);
        for (j = 2; j <= k; j++)
        if (i%j == 0)
            break;                  //若存在一个数能整除它，立刻退出循环
        if (j>k)
            printf("%d ", i);       //循环结束没有数可以整除这个数，输出这个数
    }
    return 0;
}
