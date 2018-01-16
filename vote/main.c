#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

struct vote
{
    char voter_name[20];//评分人姓名
    int goods_id;//商品编号
    float point;//评分
};

struct count
{
    float num;//某种商品的总得分
    int n;//某种商品的评分总人数
};

struct count goods[30]={{0}};

void data_in(void)
{
    struct vote new;
    strcpy(new.voter_name,"1");
    printf("Opening vote.dat...\n");
    if((fp=fopen("vote.dat","wb"))==NULL)
    {
        printf("Can't open this file\n");
        exit(0);
    }
    else printf("Open this file successfully\n");
    while(strcmp(new.voter_name,"0")!=0)
    {
        printf("\nPlease input voter_name(end with 0):");
        scanf("%s",new.voter_name);
        if(strcmp(new.voter_name,"0")==0)break;
        else
        {
            printf("Please input goods_id:");
            scanf("%d",&new.goods_id);
            getchar();
            printf("Please input point:");
            scanf("%f",&new.point);
            printf("\nSaving this data...\n");
            if(fwrite(&new,sizeof(struct vote),1,fp)!=1)
            {
                printf("Can't save this data\n");
                exit(0);
            }
            else printf("Save this data successfully\n");
        }
    }
    fclose(fp);
}

void process(struct count goods[30])
{
    int i,j=0,flag=0;
    struct vote good;
    printf("\nAnalysing data...\n");
    printf("Opening vote.dat...\n");
    if((fp=fopen("vote.dat","rb"))==NULL)
    {
        printf("Can't open this file\n");
        exit(0);
    }

    else printf("Open this file successfully\n");
    printf("Analysing data...\n");
    while(!feof(fp))
    {
        fread(&good,sizeof(struct vote),1,fp);
        goods[good.goods_id-1].num+=good.point;
        goods[good.goods_id-1].n++;
    }
    for(i=0;i<29;i++)
    {
        if(goods[i].n>300)
        {
            if(goods[i+1].num>goods[j].num)
                j=i+1;
                flag=1;
        }
    }
    if(flag)
    {
        printf("Goods_id:%d",j);
        printf("\nSum of people:%d",goods[j].n);
        printf("\nAverage of votes:%f",goods[j].num/goods[j].n);
    }
    else printf("No highest good\n");
    fclose(fp);
}

int main()
{
    data_in();
    process(goods);
    return 0;
}
