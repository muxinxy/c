#include <stdio.h>
#include <stdlib.h>

int b[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char c[]={1,0,'X',9,8,7,6,5,4,3,2};

int id(char a[])
{
    int i,sum=0;
    for(i=0;i<17;i++)
    {
        sum+=(a[i]-'0')*b[i];
    }
    if(c[sum%11]==(a[17]-'0'))
        return 1;
    else return 0;
}

int main()
{
    char a[19];
    printf("Please input a ID: ");
    gets(a);
    if(id(a))
        printf("The check code is Right!");
    else printf("The check code is Wrong!");
    return 0;
}
