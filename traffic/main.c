#include<stdio.h>
#include<stdlib.h>
int set[105],flag;
struct road
{
    int a;
    int b;
    int value;
}s[100];
int cmp(const void*a,const void*b)
{
    return (*(struct road*)a).value-(*(struct road*)b).value;
}
int Findset(int x)
{
    if(x!=set[x])
        set[x]=Findset(set[x]);
    return set[x];
}
void Unionset(int a,int b)
{
    int x=Findset(a);
    int y=Findset(b);
    if(x==y)
        return;
    set[y]=x;
    flag=1;
}
int main()
{
    int n,m,i,t,sum;
    while(scanf("%d%d",&n,&m),n)
    {
        for(i=1;i<=n;i++)
            set[i]=i;
        sum=0;t=0;
        for(i=0;i<n;i++)
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].value);
        qsort(s,n,sizeof(s[0]),cmp);
        for(i=0;i<n;i++)
        {
            flag=0;
            Unionset(s[i].a,s[i].b);
            if(flag)
            {
                sum+=s[i].value;
                t++;
            }
        }
        if(t==m-1)
            printf("%d\n",sum);
        else
            printf("?\n");
    }
    return 0;
}
