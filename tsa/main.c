#include<stdio.h>
#include<malloc.h>
#define max 100
typedef struct arcnode
{
    int adjvex;
    struct arcnode*next;
}arcnode;
typedef struct
{
    int vertex;
    arcnode*firstarc;
}vexnode;
vexnode adjlist[max];
int creatadjlist()
{
    arcnode*ptr;
    int arcnum,vexnum,k,v1,v2;
    printf("input vexnum and arcnum:");
    scanf("%d,%d",&vexnum,&arcnum);
    for(k=1;k<=vexnum;k++)
    {
        adjlist[k].firstarc=NULL;
        adjlist[k].vertex=0;
    }
    for(k=1;k<=arcnum;k++)
    {
        printf("v1,v2=");
        scanf("%d,%d",&v1,&v2);
        ptr=(arcnode*)malloc(sizeof(arcnode));
        ptr->adjvex=v2;
        ptr->next=adjlist[v1].firstarc;
        adjlist[v1].firstarc=ptr;
        adjlist[v2].vertex++;
    }
    return vexnum;
}
void toposort(int n)
{
    int queue[max];
    int front=0,rear=0;
    int v,w,m;
    arcnode*p;
    m=0;
    for(v=1;v<=n;v++)
        if(adjlist[v].vertex==0)
        {
            rear=(rear+1)%max;
            queue[rear]=v;
        }
        printf("the toposort:\n");
        while(front!=rear)
        {
            front=(front+1)%max;
            v=queue[front];
            printf("%d ",v);
            m++;
            p=adjlist[v].firstarc;
            while(p!=NULL)
            {
                w=p->adjvex;
                adjlist[w].vertex--;
                if(adjlist[w].vertex==0)
                {
                    rear=(rear+1)%max;
                    queue[rear]=w;
                }
                p=p->next;
            }
        }
        if(m<n)
            printf("the toposort is fail.");
}
int main()
{
    int n;
    n=creatadjlist();
    toposort(n);
    return 0;
}
