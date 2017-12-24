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

FILE *fp;

void rff()//read from file
{
    int i;
    if((fp=fopen("C:\\data","rb"))==NULL)
    {
        printf("can't open this file\n");
        exit(0);
    }
    for(i=0;i<N;i++)
        if(fread(&stu[i],sizeof(struct stud),1,fp)!=1)
        printf("file read error\n");
    fclose(fp);
    printf("read from file successfully\n\n");
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
    rff();
    sort();
    return 0;
}
