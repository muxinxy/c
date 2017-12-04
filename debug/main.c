#include<stdio.h>
int strstr(char *str1,char *str2)
{
    int flag=-1;
	char *place,*s1=str1,*s2=str2,*temp=str1;
	while(*s1!='\0')
	{
	    if(flag!=-1)break;
		else if(*s1==*s2)//如果s1指向的字母与s2的首字母相同
		{
			place=s1;//让place指向s1所指向的字母
			while(*s2!='\0')
			{
				if(*place==*s2)//从place指向的位置开始判断是否s1包含s2
				{
					place++;
					s2++;
				}
				else break;
			}
			if(place>s2) flag=(s1-temp)/4;//如果包含返回位置值
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
