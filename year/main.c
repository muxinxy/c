#include<stdio.h>
int main()
{
    double x,y,h;
    scanf("%f%f",x,y);
    if(x>=-3)
    {
        if(x<=-1)
        {
            if(y<3)
            {
                if(y>1)h=1;
                else h=0;
        }else h=0;
       if(y>-3)
       {
           if(y<-1)h=1;
           else h=0;
       }else h=0;
        }
        else h=0;
    }else h=0;

     if(x>=1)
    {
        if(x<=3)
        {
            if(y<3)
            {
                if(y>1)h=1;
                else h=0;
        }else h=0;
       if(y>-3)
       {
           if(y<-1)h=1;
           else h=0;
       }else h=0;
        }
        else h=0;
    }else h=0;
    printf("h=%d\n",h);
    return 0;
}
