#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c;//�������c
    int i=1;
    printf("������n���ַ���ɵ��ַ�����1<=n<=20���Կո�ָ�����");
    c=getchar();//��ʼ������c
    printf("����Ϊ��");
    while (c!='\n'&&i<=20)//�ж��ַ��Ƿ�Ϊ�س�
    {
        if (c!=32)//�ж��ַ��Ƿ�Ϊ�ո�
            {
                if ((c>='A'&&c<='V')||(c>='a'&&c<='v'))//�ж���ĸλ��
                    c=c+4;
                else
                    c=c-22;

            }
        else
            c=32;
        putchar(c);//����ַ�
        c=getchar();//����һ���ַ���ֵ������c
        i++;
    }
    return 0;
}
