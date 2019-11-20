#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char a[] =
    {
        124, 170,  29,  20, 221,   3,  39,  69,   2, 126,
        182,  54, 190, 224, 200,  90,  58, 192, 244, 199,
        71, 188, 209, 140,  98, 105,  25, 164, 230, 181,
        40,  21
    };
    unsigned char b[]=
    {
        124, 170,  29,  20, 221,   3,  39,  69,   2, 126,
        182,  54, 190, 224, 200,  90,  58, 192, 244, 199,
        71, 188, 209, 140,  98, 105,  25, 164, 230, 181,
        40,  21
    };
    srand(0xDEADBEEF);
    int v1=32,i,j,k;
    for ( i = 0; i < v1; ++i )
        a[i] += (char)random() % 64;
    for ( j = 0; j < v1; ++j )
        b[j] ^= random();
    for ( k = 0; k < v1; ++k )
    {
        a[k]-=b[k];
        printf("%c",a[k]);
    }
    return 0;
}
