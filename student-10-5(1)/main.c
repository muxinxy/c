#include <stdio.h>
#include <stdlib.h>
#define M 3//score
#define N 3//student

FILE *fp;

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

void wtf()
{
    int i;
    if((fp=fopen("C:\\data","wb"))==NULL)
    {
        printf("can't open this file\n");
        exit(0);
    }
    getchar();
    for(i=0;i<N;i++)
    {
        fwrite(&stu[i],sizeof(struct stud),1,fp);
    }
    fclose(fp);
    printf("Write to file successfully");
}

int main()
{
    data_in();
    average();
    wtf();//write to file
    return 0;
}
