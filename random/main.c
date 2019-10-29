#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((int)time(0));
    for(int i=0;i<3;i++){
        printf("%d\n",rand());
    }
    return 0;
}
