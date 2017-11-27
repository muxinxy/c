#include <stdio.h>
#include <stdlib.h>

int length=0;

int word(char str[],int i)
{
    length=0;
    while(str[i]!='\0')
    {
        if(str[i]!=32)length++;
        else if(str[i]==32&&length!=0)break;
        i++;
    }
    return (i-length);
}

int longest(char str[])
{
    int length1,start1,start2;
    start1=word(str,0);
    length1=length;
    start2=word(str,start1+length1);
    while(str[start2+length]!='\0')
    {
        if(length1<length)
        {
            length1=length;
            start1=start2;
        }
        if(str[start2+length]!='\0')
            start2=word(str,start2+length);
    }
    if(length1<length)
        {
            length1=length;
            start1=start2;
        }
    length=length1;
    return(start1);
}

int main()
{
    int start,i;
    char str[100];
    printf("Please input a sentence:\n");
    gets(str);
    start=longest(str);
    for(i=start;i<=
    start+length;i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}

