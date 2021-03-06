#include <stdio.h>
#include <stdlib.h>
#define N 20000
//亲和数：两个正整数的所有因数之和等于对方
int a[100]={0},sum=0;//数组a用于存储亲和数，sum记录亲和数的对数

int check(int x)//检查亲和数是否重复
{
    int i=0,y=0;
    for(i=0;i<100;i++)
    {
        if(a[i]==x)y=1;
    }
    return y;
}

void dn()//计算亲和数
{
    int i=0,j=0,m=0,n=0,k=0;
    for(i=2;i<=N;i++)
    {
        if(check(i))continue;//此亲和数已存在，跳过本次循环
        m=0;
        n=0;
        for(j=1;j<=i/2;j++)//计算第一个数的所有因数之和
        {
            if(i%j==0)m+=j;
        }
        for(j=1;j<m&&m<=N;j++)//将第一个数的所有因数之和作为第二个数，计算第二个数的所有因数之和
        {
            if(m%j==0)n+=j;
        }
        if(n==i)//两者相等，将这一对亲和数存入数组
        {
            a[k++]=i;
            a[k++]=j;
            sum++;//计算亲和数的对数
        }
    }
}

int main()
{
    int i=0;
    dn();
    printf("Sum=%d\n",sum);//输出亲和数的对数
    for(i=0;i<100&&a[i]!=0;i++)
    {
        printf("%d\t",a[i]);
        if((i+1)%2==0&&a[i+1]!=0)printf("\n");//每两个一行输出亲和数
    }
    return 0;
}
