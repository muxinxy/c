#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int i,j,a[N],b;
    void bubsort(int a[]);
    printf("Please input %d numbers:",N);
    for(i=0; i<N; i++)
        scanf("%d",&a[i]);
    bubsort(a);
    return 0;
}

void bubsort(int a[])
{
    int i,j,b;
    for(j=0; j<N-1; j++)
    {
        for(i=0; i<N-j-1; i++)
        {
            if(a[i]<a[i+1])
            {
                b=a[i];
                a[i]=a[i+1];
                a[i+1]=b;
            }
        }
    }
    printf("The result of sorting is:");
    for(i=0; i<N; i++)
        printf("%d ",a[i]);
}
