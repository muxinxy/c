#include<stdio.h>
int strstr(char *str1,char *str2)
{
    int flag=-1;
	char *place,*s1=str1,*s2=str2,*temp=str1;
	while(*s1!='\0')
	{
	    if(flag!=-1)break;
		else if(*s1==*s2)//���s1ָ�����ĸ��s2������ĸ��ͬ
		{
			place=s1;//��placeָ��s1��ָ�����ĸ
			while(*s2!='\0')
			{
				if(*place==*s2)//��placeָ���λ�ÿ�ʼ�ж��Ƿ�s1����s2
				{
					place++;
					s2++;
				}
				else break;
			}
			if(place>s2) flag=(s1-temp)/4;//�����������λ��ֵ
			else flag=-1;
		}
		s1++;
	}
	return (flag);
}
int main()
{
	char st1[]="Hello world",st2[]="or";
	int x;
	x=strstr(st1,st2);
	printf("%d",x);
	return 0;
}
