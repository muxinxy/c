#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)

struct student
{
    long num;
    float score;
    struct student *next;
};

int n=0;

struct student *insert(struct student *head,struct student *p)
{
    struct student *p0,*p1,*p2;
    p1=head;
    p0=p;
    if(head==NULL)
    {
        head=p0;
        p0->next=NULL;
    }
    else
    {
        while((p0->num>p1->num)&&p1->next!=NULL)
        {
            p2=p1;
            p1=p1->next;

        }
        if(p0->num<=p1->num)
        {
            if(head->num>p0->num)
                head=p0;
            else
                p2->next=p0;
            p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    n++;
    return(head);
};

struct student *create(void)
{
    struct student *insert(struct student *head,struct student *stud);
    struct student *head,*p;
    p=(struct student *)malloc(LEN);
    scanf("%ld,%f",&p->num,&p->score);
    head=NULL;
    while(p->num!=0)
    {
        head=insert(head,p);
        p=(struct student *)malloc(LEN);
        scanf("%ld,%f",&p->num,&p->score);
    }
    free(p);
    return(head);
};


void print(struct student *head)
{
    struct student *p;
    if(head==NULL)
        printf("\nList is empty!\n");
    else
    {
        p=head;
        printf("\nThere are %d data in the list below:\nnum\tscore\n",n);
        while(p!=NULL)
        {
            printf("%ld\t%-.2f\n",p->num,p->score);
            p=p->next;
        }
        printf("\n");
    }
}

struct student *del(struct student *head,struct student *p)
{
    struct student *p0,*p1,*p2;
    p1=head;
    p0=p;
    if(head!=NULL)
    {
        while((p0->num>p1->num)&&p1->next!=NULL)
        {
            p2=p1;
            p1=p1->next;
        }
        if((p1->num==p0->num)&&p1!=head)
        {
            p2->next=p1->next;
            free(p1);
            n--;
        }
        else if((p1->num==p0->num)&&p1==head)
        {
            head=p1->next;
            free(p1);
            n--;
        }
        else printf("No num found!\n");
    }
    return(head);
};

int main()
{
    int select;
    struct student *p,*head;
    head=NULL;
    while(select!=3)
    {
            printf("1.insert\t2.delete\t3.exit\n");
            select=-1;
            printf("Please input the number of menu:");
            scanf("%d",&select);
            getchar();
            switch(select)
            {
                case 1: printf("Please input the num and the score(end with 0,0):\n");
                        if(head==NULL)head=create();
                        else
                        {
                            p=(struct student*)malloc(LEN);
                            scanf("%ld,%f",&p->num,&p->score);
                            head=insert(head,p);
                            printf("Inserted: %ld\n",p->num);
                        }
                        print(head);
                        break;
                case 2: if(head==NULL)printf("\nList is empty!\n");
                        else
                        {
                            printf("Please input the num:\n");
                            p=(struct student*)malloc(LEN);
                            scanf("%ld",&p->num);
                            head=del(head,p);
                            print(head);
                        }
            }
    }
    return 0;
}
