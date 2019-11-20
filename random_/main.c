#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1,i,j,k;
    char input[100];
    char marg_num[100]={124,170,29,20,221,3,
    39,69,2,126,182,54,190,224,200,90,58,192,
    244,199,71,188,209,140,98,105,25,164,230,181,40,21};
    srand(0xDEADBEEF);
    v1 = strlen(input);
    for ( i = 0; i < v1; ++i )
        input[i] += (char)random() % 64;
    for ( j = 0; j < v1; ++j )
        input[j] ^= random();
    for ( k = 0; k < v1; ++k )
    {
        if ( input[k] != marg_num[k] )
        return 0LL;
    }
    return 1LL;
}
