#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[21];//�����ַ���
    printf("������n���ַ���ɵ��ַ�����1<=n<=20���Կո�ָ�����");
    gets(str);//�����ַ���
    int i,len=strlen(str);//�����������i���ַ�������len
    for (i=0;i<len&&str[i]!='\n';i++)//ѭ���忪ʼ
    {
        if (str[i]!=32)//�ж��ַ��Ƿ�Ϊ�ո�
            {
                if ((str[i]>='A'&&str[i]<='V')||(str[i]>='a'&&str[i]<='v'))//�ж���ĸλ��
                    str[i]=str[i]+4;
                else
                    str[i]=str[i]-22;

            }
        else
            str[i]=32;
    }
    printf("����Ϊ��");
    puts(str);//���ת������ַ���
    return 0;
}
