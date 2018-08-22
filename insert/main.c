#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10]={1,2,3,4,5,6,7,9,11};
    int i,n,bot=0,top=8;
    printf("Please input an integer:");
    scanf("%d",&n);
    printf("Old a[]=");
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    if(n>a[8])a[9]=n;
    else{
        if(n<a[0])top=0;
        else{
            while(top>bot+1){
                if(n>a[(bot+top)/2])bot=(bot+top)/2;
                else top=(bot+top)/2;
            }
        }
        for(i=8;i>=top;i--){
            a[i+1]=a[i];
        }
        a[top]=n;
    }
    printf("\nNew a[]=");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
