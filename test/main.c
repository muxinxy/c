#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k,m,n;
    scanf("%d %d",&m,&n);
    for (i = m; i <= n; i += 1)  //ż���ز�����������101��ʼ��iÿѭ��һ�μӶ�
    {
        k = sqrt(i);
        for (j = 2; j <= k; j++)
        if (i%j == 0)
            break;                  //������һ�������������������˳�ѭ��
        if (j>k)
            printf("%d ", i);       //ѭ������û���������������������������
    }
    return 0;
}
