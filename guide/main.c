#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLACE_NAME_LENGTH 100//�ص����Ƴ���
#define PLACE_INFO_LENGTH 100//�ص���Ϣ����
#define PLACE_SUM 32//�ص����
#define INF 9999//���������ľ���

int map[PLACE_SUM+1][PLACE_SUM+1];//��ͼ�Ĵ�Ȩ�ڽӾ���

/**
* �洢�ص���Ϣ�Ľṹ��
*/
struct place
{
    char name[PLACE_NAME_LENGTH];
    char show_name[PLACE_NAME_LENGTH];
    char info[PLACE_INFO_LENGTH];
}pla[PLACE_SUM+1];

/**
* ��ʼ����ͼ
*/
void init()
{
    int i,j;
    strcpy(pla[1].name, "������");
    strcpy(pla[1].show_name, "������             ");
    strcpy(pla[1].info, "У�����ţ����Ե�����");
    strcpy(pla[2].name, "������");
    strcpy(pla[2].show_name, "������             ");
    strcpy(pla[2].info, "ͨ����������");
    strcpy(pla[3].name, "����");
    strcpy(pla[3].show_name, "����               ");
    strcpy(pla[3].info, "ͨ����������");
    strcpy(pla[4].name, "����");
    strcpy(pla[4].show_name, "����               ");
    strcpy(pla[4].info, "��������");
    strcpy(pla[5].name, "����");
    strcpy(pla[5].show_name, "����               ");
    strcpy(pla[5].info, "��������");
    strcpy(pla[6].name, "����");
    strcpy(pla[6].show_name, "����               ");
    strcpy(pla[6].info, "��������");
    strcpy(pla[7].name, "УҽԺ");
    strcpy(pla[7].show_name, "УҽԺ             ");
    strcpy(pla[7].info, "УҽԺ��ɽУ�����ﲿ");
    strcpy(pla[8].name, "������");
    strcpy(pla[8].show_name, "������             ");
    strcpy(pla[8].info, "������Ӿ�ݡ�������ݡ�����ϵ��");
    strcpy(pla[9].name, "һ��");
    strcpy(pla[9].show_name, "һ��               ");
    strcpy(pla[9].info, "��һʳ�ã���������");
    strcpy(pla[10].name, "����");
    strcpy(pla[10].show_name, "����               ");
    strcpy(pla[10].info, "�ڶ�ʳ�ã���������");
    strcpy(pla[11].name, "����");
    strcpy(pla[11].show_name, "����                ");
    strcpy(pla[11].info, "���������Ĳٳ�");
    strcpy(pla[12].name, "����");
    strcpy(pla[12].show_name, "����                ");
    strcpy(pla[12].info, "���������Ĳٳ�");
    strcpy(pla[13].name, "����Ƽ���¥");
    strcpy(pla[13].show_name, "����Ƽ���¥        ");
    strcpy(pla[13].info, "����Ƽ���¥");
    strcpy(pla[14].name, "��ѧ��");
    strcpy(pla[14].show_name, "��ѧ��              ");
    strcpy(pla[14].info, "���ж����˺Ž�ѧ¥������㳡������㳡��");
    strcpy(pla[15].name, "�ű�");
    strcpy(pla[15].show_name, "�ű�                ");
    strcpy(pla[15].info, "��Ϣ��ѧ�빤��ѧԺ��¥");
    strcpy(pla[16].name, "����");
    strcpy(pla[16].show_name, "����                ");
    strcpy(pla[16].info, "��Ϣ��ѧ�빤��ѧԺ��¥");
    strcpy(pla[17].name, "����ѧԺ");
    strcpy(pla[17].show_name, "����ѧԺ            ");
    strcpy(pla[17].info, "����ѧԺ");
    strcpy(pla[18].name, "���Ͽ�ѧ�빤��ѧԺ");
    strcpy(pla[18].show_name, "���Ͽ�ѧ�빤��ѧԺ");
    strcpy(pla[18].info, "���Ͽ�ѧ�빤��ѧԺ");
    strcpy(pla[19].name, "���������ѧԺ");
    strcpy(pla[19].show_name, "���������ѧԺ      ");
    strcpy(pla[19].info, "���������ѧԺ");
    strcpy(pla[20].name, "��ѧ����ѧԺ");
    strcpy(pla[20].show_name, "��ѧ����ѧԺ        ");
    strcpy(pla[20].info, "��ѧ����ѧԺ");
    strcpy(pla[21].name, "������ѧ�빤��ѧԺ");
    strcpy(pla[21].show_name, "������ѧ�빤��ѧԺ");
    strcpy(pla[21].info, "������ѧ�빤��ѧԺ");
    strcpy(pla[22].name, "�����ѧѧԺ");
    strcpy(pla[22].show_name, "�����ѧѧԺ        ");
    strcpy(pla[22].info, "�����ѧѧԺ");
    strcpy(pla[23].name, "��Զ¥");
    strcpy(pla[23].show_name, "��Զ¥              ");
    strcpy(pla[23].info, "��������������");
    strcpy(pla[24].name, "��֪¥");
    strcpy(pla[24].show_name, "��֪¥              ");
    strcpy(pla[24].info, "Ҳ��������������");
    strcpy(pla[25].name, "ͼ���");
    strcpy(pla[25].show_name, "ͼ���              ");
    strcpy(pla[25].info, "���������ϰ�ĵط�");
    strcpy(pla[26].name, "����");
    strcpy(pla[26].show_name, "����              ");
    strcpy(pla[26].info, "����");
    strcpy(pla[27].name, "��ѧԺ");
    strcpy(pla[27].show_name, "��ѧԺ              ");
    strcpy(pla[27].info, "��ѧԺ");
    strcpy(pla[28].name, "����ѧԺ");
    strcpy(pla[28].show_name, "����ѧԺ            ");
    strcpy(pla[28].info, "����ѧԺ");
    strcpy(pla[29].name, "����ѧԺ");
    strcpy(pla[29].show_name, "����ѧԺ            ");
    strcpy(pla[29].info, "����ѧԺ");
    strcpy(pla[30].name, "�����ѧԺ");
    strcpy(pla[30].show_name, "�����ѧԺ          ");
    strcpy(pla[30].info, "�����ѧԺ");
    strcpy(pla[31].name, "��ѧ��ѧѧԺ");
    strcpy(pla[31].show_name, "��ѧ��ѧѧԺ        ");
    strcpy(pla[31].info, "��ѧ��ѧѧԺ");
    strcpy(pla[32].name, "����������վ");
    strcpy(pla[32].show_name, "����������վ        ");
    strcpy(pla[32].info, "ȡ�����ļ�");

    for(i=1;i<=PLACE_SUM;i++)
    {
        for(j=1;j<=PLACE_SUM;j++)
        {
            if(i==j)
            {
                map[i][j]=0;
            }
            else
            {
                map[i][j]=INF;
            }
        }
    }

    map[1][8]=160;//�����ŵ�������160��
    map[8][1]=160;
    map[1][13]=150;//�����ŵ�����Ƽ���¥150��
    map[13][1]=150;
    map[2][5]=135;//�����ŵ�����135��
    map[5][2]=135;
    map[2][24]=147;//�����ŵ���֪¥147��
    map[24][2]=147;
    map[2][23]=242;//�����ŵ���Զ¥242��
    map[23][2]=242;
    map[2][25]=457;//�����ŵ�ͼ���457��
    map[25][2]=457;
    map[3][6]=200;//���ŵ�����200��
    map[6][3]=200;
    map[3][12]=100;//���ŵ�����100��
    map[12][3]=100;
    map[3][27]=869;//���ŵ���ѧԺ869��
    map[27][3]=869;
    map[4][9]=80;//������һ��80��
    map[9][4]=80;
    map[4][26]=150;//����������150��
    map[26][4]=150;
    map[4][7]=300;//������УҽԺ300��
    map[7][4]=300;
    map[4][11]=160;//����������160��
    map[11][4]=160;
    map[8][11]=260;//�����ݵ�����260��
    map[11][8]=260;
    map[8][14]=80;//�����ݵ���ѧ��80��
    map[14][8]=80;
    map[9][10]=20;//һ�͵�����20��
    map[10][9]=20;
    map[9][14]=180;//һ�͵���ѧ��180��
    map[14][9]=180;
    map[9][26]=160;//һ�͵�����160��
    map[26][9]=160;
    map[9][32]=120;//һ�͵�����������վ120��
    map[32][9]=120;
    map[12][26]=50;//���ٵ�����50��
    map[26][12]=50;
    map[12][27]=720;//���ٵ���ѧԺ720��
    map[27][12]=720;
    map[13][14]=20;//����Ƽ���¥����ѧ��20��
    map[14][13]=20;
    map[13][17]=382;//����Ƽ���¥������ѧԺ382��
    map[17][13]=382;
    map[13][18]=475;//����Ƽ���¥�����Ͽ�ѧ�빤��ѧԺ475��
    map[18][13]=475;
    map[14][15]=100;//��ѧ�����ű�100��
    map[15][14]=100;
    map[14][17]=200;//��ѧ��������ѧԺ200��
    map[17][14]=200;
    map[14][18]=120;//��ѧ�������Ͽ�ѧ�빤��ѧԺ120��
    map[18][14]=120;
    map[14][19]=120;//��ѧ�������������ѧԺ120��
    map[19][14]=120;
    map[15][16]=100;//�ű�������100��
    map[16][15]=100;
    map[15][21]=240;//�ű���������ѧ�빤��ѧԺ240��
    map[21][15]=240;
    map[16][21]=240;//���ϵ�������ѧ�빤��ѧԺ240��
    map[21][16]=240;
    map[16][23]=354;//���ϵ���Զ¥354��
    map[23][16]=354;
    map[16][25]=365;//���ϵ�ͼ���365��
    map[25][16]=365;
    map[16][27]=509;//���ϵ���ѧԺ509��
    map[27][16]=509;
    map[17][18]=168;//����ѧԺ�����Ͽ�ѧ�빤��ѧԺ168��
    map[18][17]=168;
    map[17][20]=187;//����ѧԺ����ѧ����ѧԺ187��
    map[20][17]=187;
    map[18][19]=17;//���Ͽ�ѧ�빤��ѧԺ�����������ѧԺ17��
    map[19][18]=17;
    map[18][20]=64;//���Ͽ�ѧ�빤��ѧԺ����ѧ����ѧԺ64��
    map[20][18]=64;
    map[18][21]=114;//���Ͽ�ѧ�빤��ѧԺ��������ѧ�빤��ѧԺ114��
    map[21][18]=114;
    map[19][21]=96;//���������ѧԺ��������ѧ�빤��ѧԺ96��
    map[21][19]=96;
    map[20][21]=34;//��ѧ����ѧԺ��������ѧ�빤��ѧԺ34��
    map[21][20]=34;
    map[21][22]=28;//������ѧ�빤��ѧԺ�������ѧѧԺ28��
    map[22][21]=28;
    map[22][23]=118;//�����ѧѧԺ����Զ¥118��
    map[23][22]=118;
    map[22][25]=374;//�����ѧѧԺ��ͼ���374��
    map[25][22]=374;
    map[23][24]=112;//��Զ¥����֪¥112��
    map[24][23]=112;
    map[23][25]=435;//��Զ¥��ͼ���435��
    map[25][23]=435;
    map[25][27]=301;//ͼ��ݵ���ѧԺ301��
    map[27][25]=301;
    map[25][31]=285;//ͼ��ݵ���ѧ��ѧѧԺ285��
    map[31][25]=285;
    map[26][32]=50;//���򳡵�����������վ50��
    map[32][26]=50;
    map[27][28]=50;//��ѧԺ������ѧԺ50��
    map[28][27]=50;
    map[28][29]=50;//����ѧԺ������ѧԺ50��
    map[29][28]=50;
    map[29][30]=150;//����ѧԺ�������ѧԺ150��
    map[30][29]=150;
    map[30][31]=100;//�����ѧԺ����ѧ��ѧѧԺ100��
    map[31][30]=100;
}

/**
* �ص��б�
*/
void list()
{
    int i;
    printf("                                                  �ص��б�");
    printf("\n*********************************************************************************************************\n*\t");
    for(i=1;i<=PLACE_SUM;i++)
    {
        printf("%d.%s\t",i,pla[i].show_name);
        if(i%4==0 && i!=PLACE_SUM)
        {
            printf("*\n*\t");
        }
    }
    printf("*\n*********************************************************************************************************\n");
}

/**
* �������
*/
int fun_number()
{
    int number;
    printf("������ص���ţ�");
    scanf("%d",&number);
    while(number<1 || number>PLACE_SUM)
    {
        printf("�ص���ų�����Χ������������ص���ţ�");
        scanf("%d",&number);
    }
    return number;
}

/**
* ��������
*/
int fun_name()
{
    int i,number;
    char name[PLACE_NAME_LENGTH];
    printf("������ص����ƣ�");
    scanf("%s",name);
    number=0;
    while(number==0)
    {
        for(i=1;i<=PLACE_SUM;i++)
        {
            if(strcmp(pla[i].name, name)==0)
            {
                number=i;
                break;
            }
        }
        if(number==0)
        {
            printf("�ص����Ʋ����ڣ�����������ص����ƣ�");
            scanf("%s",name);
        }
    }
    return number;
}

/**
* �ص����
*/
void information()
{
    int op=1,number=0;
    while(op!=3)
    {
        printf("*********************************************************\n");
        printf("*\t1.����Ų�ѯ\t2.�����Ʋ�ѯ\t3.������һ��\t*\n");
        printf("*********************************************************\n");
        printf("������ѡ�");
        scanf("%d",&op);
        while(op!=1 && op!=2 && op!=3)
        {
            printf("�����������������ѡ�");
            scanf("%d",&op);
        }
        switch(op)
        {
            case 1:
                number=fun_number();
                printf("\n�ص���ţ�%d\n�ص����ƣ�%s\n�ص���ܣ�%s\n\n",number,pla[number].show_name,pla[number].info);
                break;
            case 2:
                number=fun_name();
                printf("\n�ص���ţ�%d\n�ص����ƣ�%s\n�ص���ܣ�%s\n\n",number,pla[number].show_name,pla[number].info);
                break;
            case 3:break;
        }
    }
}

/**
* ·�߹滮
* �Ͻ�˹�����㷨�����·��
*/
void guide()
{
    int i,j,u,v,op=0;
    int min=INF,start,end;//��̾��룬��ʼ�ص���ţ������ص����
    int path[PLACE_SUM+1]={0},flag[PLACE_SUM+1]={0},dis[PLACE_SUM+1];//path����洢���·����flag����洢��־��Ϣ��0��ʾ��·��֮�⣬1��ʾ��·���ϣ�
    int path2[PLACE_SUM+1]={0};
    while(op!=3)
    {
        for(i=0;i<=PLACE_SUM;i++)
        {
            path[i]=0;
            flag[i]=0;
        }
        printf("*********************************************************\n");
        printf("*\t1.����Ź滮\t2.�����ƹ滮\t3.������һ��\t*\n");
        printf("*********************************************************\n");
        printf("������ѡ�");
        scanf("%d",&op);
        while(op!=1 && op!=2 && op!=3)
        {
            printf("�����������������ѡ�");
            scanf("%d",&op);
        }
        switch(op)
        {
            case 1:
                printf("\n��ʼ�ص����\n");
                start=fun_number();
                printf("\n�����ص����\n");
                end=fun_number();
                break;
            case 2:
                printf("\n��ʼ�ص�����\n");
                start=fun_name();
                printf("\n�����ص�����\n");
                end=fun_name();
                break;
            case 3:break;

        }
        if(op==3)
        {
            break;
        }
        for(i=1;i<=PLACE_SUM;i++)
        {
            dis[i]=map[start][i];
            if(dis[i]<INF)
                path[i]=start;
        }
        flag[start]=1;
        for(i=1;i<end;i++)
        {
            min=INF;
            for(j=1;j<=PLACE_SUM;j++)
            {
                if(flag[j]==0 && dis[j]<min)
                {
                    min=dis[j];
                    u=j;
                }
            }
            flag[u]=1;
            for(v=1;v<=PLACE_SUM;v++)
            {
                if(flag[v]==0 && dis[v]>dis[u]+map[u][v])
                {
                    path[v]=u;
                    dis[v]=dis[u]+map[u][v];
                }
            }
        }
        v=end;
        i=1;
        while(path[v]!=start)
        {
            path2[i++]=path[v];
            v=path[v];
        }
        u=i-1;
        printf("\n·�ߣ�");
        printf("%s -> ",pla[start].name);
        for(j=u;j>=1;j--)
        {
            printf("%s -> ",pla[path2[j]].name);
        }
        printf("%s\n\n",pla[end].name);
    }
}

int main()
{
    int op=0;
    init();
    while(op!=4)
    {
        system("cls");
        printf("\n     �й������ѧ��ɽУ��У԰����ϵͳ\n");
        printf("*****************************************\n");
        printf("*\t1.�ص��б�\t2.�ص����\t*\n*\t3.·�߹滮\t4.�˳�ϵͳ\t*\n");
        printf("*****************************************\n");
        printf("������ѡ�");
        scanf("%d",&op);
        while(op!=1 && op!=2 && op!=3 && op!=4)
        {
            printf("�����������������ѡ�");
            scanf("%d",&op);
        }
        switch(op)
        {
            case 1:list();getchar();getchar();break;
            case 2:information();break;
            case 3:guide();break;
            case 4:break;
        }
    }
    return 0;
}
