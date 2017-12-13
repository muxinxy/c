#include <stdio.h>
#include <stdlib.h>
#define M 3//score
#define N 3//student

struct date
{
    int year;
    int month;
    int day;
};

struct stud
{
    char num[12];
    char name[9];
    char sex;
    struct date birth;
    float score[M];
    float ave;
};

struct stud stu[N];

void data_in()//input data
{
    int i,j;
    for(i=0;i<N;i++)
    {
        printf("Please input No.%d student's information:\n",i+1);
        printf("Please input the number:");
        scanf("%s",stu[i].num);
        printf("Please input the name:");
        scanf("%s",stu[i].name);
        getchar();
        printf("Please input the sex(f/m):");
        stu[i].sex=getchar();
        getchar();
        printf("Please input the date of birth(yyyy-mm-dd):");
        scanf("%d-%d-%d",&stu[i].birth.year,&stu[i].birth.month,&stu[i].birth.day);
        for(j=0;j<M;j++)
        {
            printf("Please input the No.%d score:",j+1);
            scanf("%f",&stu[i].score[j]);
        }
        printf("\n");
    }
}

void average()//average of score
{
    int i,j;
    double sum;
    for(i=0;i<N;i++)
    {
        sum=0;
        for(j=0;j<M;j++)
        {
            sum+=stu[i].score[j];
        }
        stu[i].ave=sum/M;
    }
}

void print(struct stud *pt)//print the table
{
    int j;
    printf("%-15s",pt->num);
    printf("%-15s",pt->name);
    if(pt->sex=='m')printf("male           ");//print the sex according to whether the sex is f or m
    else printf("female         ");
    printf("%d",pt->birth.year);
    if(pt->birth.month<10)printf("-0%d",pt->birth.month);//if the month is below 10, append 0 before it
    else printf("-%d",pt->birth.month);
    if(pt->birth.day<10)printf("-0%-7d",pt->birth.day);
    else printf("-%-7d ",pt->birth.day);
    for(j=0;j<M;j++)
    {
        printf("%-15f",pt->score[j]);
    }
    printf("%-15f",pt->ave);
}

void sort()//sort the scores
{
    int i,j;
    struct stud *p;
    p=stu;
    struct stud temp;
    for(i=0;i<N;i++)//use the bubble sort
    {
        for(j=0;j<N-i;j++)
        {
            if((p+j)->ave<(p+j+1)->ave)
            {
                temp=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=temp;
            }
        }
    }
    printf("No  number         name           sex            birth           score1         score2         score3         average        \n");//table tittle
    for(;p<stu+N;p++)
    {
        printf("%d   ",p-stu+1);//print the number of order
        print(p);
        if(p!=stu+3)printf("\n");
    }
}

int main()
{
    data_in();
    average();
    sort();
    return 0;
}
