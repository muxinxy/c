#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strstr1(char *str1,char *str2)
{
    int i=0,j=0,flag=0;
    int s=strlen(str2);
    while(str1[i]!='\0'&&j<s)
    {
        if(str1[i]==str2[j])
        {
            flag=1;
            j++;
        }
        else
        {
            flag=0;
            j=0;
        }
        i++;
        if(j==s)break;
    }
    if(flag)return(i-s);
    else return(-1);
}

int main()
{
    int i;
    char a[100],b[100];
    printf("Please input string a:");
    gets(a);
    printf("Please input string b:");
    gets(b);
    char *str1,*str2;
    str1=a;
    str2=b;
    i=strstr1(str1,str2);
    if(i>=0)
    {
        printf("True,start from No.%d.",i+1);
    }
    else printf("False.");
    return 0;
}
