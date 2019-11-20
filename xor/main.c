#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[30]={102, 109,  99, 100, 127, 124,  99, 116,  87, 112,
  101, 126,  83, 102,  96,  96, 103,  78,  74, 124,
  102, 104};
    int i;
    //scanf("%s",a);
    for(i=0;i<=21;++i)
    {
        a[i]^=i;
    }
    printf("%s\n",a);
    return 0;
}
