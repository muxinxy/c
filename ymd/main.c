#include <stdio.h>
#include <stdlib.h>

int years(int year)//�ж�����
{
    if(year%400==0||(year%4==0&&year%100!=0))return(29);
    else return(28);
}

int main()//�����������������գ��ж���Ϊ��һ��ĵڼ���
{
    int y,m,d,sum=0,i;
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30};//����һ��ÿ������������
    printf("Please input year,month,day:");
    scanf("%d-%d-%d",&y,&m,&d);//����������
    month[2]=years(y);//�������꺯������2���������¸�ֵ
    for(i=0;i<m;i++)
    {
        sum=sum+month[i];
    }
    sum=sum+d;//��������
    printf("%d-%d-%d is the No.%d day of %d",y,m,d,sum,y);
    return 0;
}
