#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int i,a[N];
    void selsort(int[]);
    printf("Please input %d numbers:",N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    selsort(a);
    return 0;
}

void selsort(int a[]){
    int i,j,b=0;
    for (i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            if(a[i]<a[j]){
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    printf("The result of the sorting is:");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
}
