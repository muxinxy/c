#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLACE_NAME_LENGTH 100//地点名称长度
#define PLACE_INFO_LENGTH 100//地点信息长度
#define ROAD_NAME_LENGTH 100//道路名称长度
#define PLACE_SUM 32//地点个数
#define ROAD_SUM 12//道路条数
#define INF 9999//代替无穷大的距离

int map[PLACE_SUM+1][PLACE_SUM+1];//地图的带权邻接矩阵
int rdm[PLACE_SUM+1][PLACE_SUM+1];//地图的道路矩阵

struct road
{
    char name[ROAD_NAME_LENGTH];//道路名称
}rd[ROAD_SUM+1];

/**
* 存储地点信息的结构体
*/
struct place
{
    char name[PLACE_NAME_LENGTH];//地点名称
    char show_name[PLACE_NAME_LENGTH];//显示所需的地点名称
    char info[PLACE_INFO_LENGTH];//地点信息
}pla[PLACE_SUM+1];

/**
* 初始化地图
*/
void init()
{
    int i,j;
    strcpy(pla[1].name, "西北门");
    strcpy(pla[1].show_name, "西北门             ");
    strcpy(pla[1].info, "校区主门，正对地铁口");
    strcpy(pla[2].name, "西南门");
    strcpy(pla[2].show_name, "西南门             ");
    strcpy(pla[2].info, "通往南区宿舍");
    strcpy(pla[3].name, "东门");
    strcpy(pla[3].show_name, "东门               ");
    strcpy(pla[3].info, "通往东区宿舍");
    strcpy(pla[4].name, "北区");
    strcpy(pla[4].show_name, "北区               ");
    strcpy(pla[4].info, "北区宿舍");
    strcpy(pla[5].name, "南区");
    strcpy(pla[5].show_name, "南区               ");
    strcpy(pla[5].info, "南区宿舍");
    strcpy(pla[6].name, "东区");
    strcpy(pla[6].show_name, "东区               ");
    strcpy(pla[6].info, "东区宿舍");
    strcpy(pla[7].name, "校医院");
    strcpy(pla[7].show_name, "校医院             ");
    strcpy(pla[7].info, "校医院崂山校区门诊部");
    strcpy(pla[8].name, "体育馆");
    strcpy(pla[8].show_name, "体育馆             ");
    strcpy(pla[8].info, "内有游泳馆、各类球馆、体育系等");
    strcpy(pla[9].name, "一餐");
    strcpy(pla[9].show_name, "一餐               ");
    strcpy(pla[9].info, "第一食堂，靠近北区");
    strcpy(pla[10].name, "二餐");
    strcpy(pla[10].show_name, "二餐               ");
    strcpy(pla[10].info, "第二食堂，靠近北区");
    strcpy(pla[11].name, "北操");
    strcpy(pla[11].show_name, "北操                ");
    strcpy(pla[11].info, "靠近北区的操场");
    strcpy(pla[12].name, "东操");
    strcpy(pla[12].show_name, "东操                ");
    strcpy(pla[12].info, "靠近东区的操场");
    strcpy(pla[13].name, "海洋科技大楼");
    strcpy(pla[13].show_name, "海洋科技大楼        ");
    strcpy(pla[13].info, "海洋科技大楼");
    strcpy(pla[14].name, "教学区");
    strcpy(pla[14].show_name, "教学区              ");
    strcpy(pla[14].info, "内有二至八号教学楼、二五广场、九球广场等");
    strcpy(pla[15].name, "信北");
    strcpy(pla[15].show_name, "信北                ");
    strcpy(pla[15].info, "信息科学与工程学院北楼");
    strcpy(pla[16].name, "信南");
    strcpy(pla[16].show_name, "信南                ");
    strcpy(pla[16].info, "信息科学与工程学院南楼");
    strcpy(pla[17].name, "工程学院");
    strcpy(pla[17].show_name, "工程学院            ");
    strcpy(pla[17].info, "工程学院");
    strcpy(pla[18].name, "材料科学与工程学院");
    strcpy(pla[18].show_name, "材料科学与工程学院");
    strcpy(pla[18].info, "材料科学与工程学院");
    strcpy(pla[19].name, "海洋与大气学院");
    strcpy(pla[19].show_name, "海洋与大气学院      ");
    strcpy(pla[19].info, "海洋与大气学院");
    strcpy(pla[20].name, "化学化工学院");
    strcpy(pla[20].show_name, "化学化工学院        ");
    strcpy(pla[20].info, "化学化工学院");
    strcpy(pla[21].name, "环境科学与工程学院");
    strcpy(pla[21].show_name, "环境科学与工程学院");
    strcpy(pla[21].info, "环境科学与工程学院");
    strcpy(pla[22].name, "地球科学学院");
    strcpy(pla[22].show_name, "地球科学学院        ");
    strcpy(pla[22].info, "地球科学学院");
    strcpy(pla[23].name, "行远楼");
    strcpy(pla[23].show_name, "行远楼              ");
    strcpy(pla[23].info, "不清楚用来干嘛的");
    strcpy(pla[24].name, "行知楼");
    strcpy(pla[24].show_name, "行知楼              ");
    strcpy(pla[24].info, "也不清楚用来干嘛的");
    strcpy(pla[25].name, "图书馆");
    strcpy(pla[25].show_name, "图书馆              ");
    strcpy(pla[25].info, "看书借书自习的地方");
    strcpy(pla[26].name, "网球场");
    strcpy(pla[26].show_name, "网球场              ");
    strcpy(pla[26].info, "网球场");
    strcpy(pla[27].name, "法学院");
    strcpy(pla[27].show_name, "法学院              ");
    strcpy(pla[27].info, "法学院");
    strcpy(pla[28].name, "管理学院");
    strcpy(pla[28].show_name, "管理学院            ");
    strcpy(pla[28].info, "管理学院");
    strcpy(pla[29].name, "经济学院");
    strcpy(pla[29].show_name, "经济学院            ");
    strcpy(pla[29].info, "经济学院");
    strcpy(pla[30].name, "外国语学院");
    strcpy(pla[30].show_name, "外国语学院          ");
    strcpy(pla[30].info, "外国语学院");
    strcpy(pla[31].name, "数学科学学院");
    strcpy(pla[31].show_name, "数学科学学院        ");
    strcpy(pla[31].info, "数学科学学院");
    strcpy(pla[32].name, "北区菜鸟驿站");
    strcpy(pla[32].show_name, "北区菜鸟驿站        ");
    strcpy(pla[32].info, "取件、寄件");

    strcpy(rd[0].name, "无");
    strcpy(rd[1].name, "入口");
    strcpy(rd[2].name, "敏行西路");
    strcpy(rd[3].name, "敏行中路");
    strcpy(rd[4].name, "励志路");
    strcpy(rd[5].name, "海源北路");
    strcpy(rd[6].name, "海源西路");
    strcpy(rd[7].name, "海源中路");
    strcpy(rd[8].name, "海源东路");
    strcpy(rd[9].name, "海源南路");
    strcpy(rd[10].name, "清淤路");
    strcpy(rd[11].name, "海大路");
    strcpy(rd[12].name, "学院路");

    for(i=1;i<=PLACE_SUM;i++)//初始化地图的邻接矩阵
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
            rdm[i][j]=0;
        }
    }

    map[1][8]=map[8][1]=160;//西北门到体育馆160米
    rdm[1][8]=rdm[8][1]=1;
    map[1][13]=map[13][1]=150;//西北门到海洋科技大楼150米
    rdm[1][13]=rdm[13][1]=1;
    map[2][5]=map[5][2]=135;//西南门到南区135米
    rdm[2][5]=rdm[5][2]=11;
    map[2][24]=map[24][2]=147;//西南门到行知楼147米
    rdm[2][24]=rdm[24][2]=1;
    map[2][23]=map[23][2]=242;//西南门到行远楼242米
    rdm[2][23]=rdm[23][2]=1;
    map[2][25]=map[25][2]=457;//西南门到图书馆457米
    rdm[2][25]=rdm[25][2]=9;
    map[3][6]=map[6][3]=200;//东门到东区200米
    rdm[3][6]=rdm[6][3]=10;
    map[3][12]=map[12][3]=100;//东门到东操100米
    rdm[3][12]=rdm[12][3]=1;
    map[3][27]=map[27][3]=869;//东门到法学院869米
    rdm[3][27]=rdm[27][3]=8;
    map[4][9]=map[9][4]=80;//北区到一餐80米
    rdm[4][9]=rdm[9][4]=3;
    map[4][26]=map[26][4]=150;//北区到网球场150米
    rdm[4][26]=rdm[26][4]=4;
    map[4][7]=map[7][4]=300;//北区到校医院300米
    rdm[4][7]=rdm[7][4]=3;
    map[4][11]=map[11][4]=160;//北区到北操160米
    rdm[4][11]=rdm[11][4]=4;
    map[8][11]=map[11][8]=260;//体育馆到北操260米
    rdm[8][11]=rdm[11][8]=2;
    map[8][14]=map[14][8]=80;//体育馆到教学区80米
    rdm[8][14]=rdm[14][8]=6;
    map[9][10]=map[10][9]=20;//一餐到二餐20米
    rdm[9][10]=rdm[10][9]=3;
    map[9][14]=map[14][9]=180;//一餐到教学区180米
    rdm[9][14]=rdm[14][9]=3;
    map[9][26]=map[26][9]=160;//一餐到网球场160米
    rdm[9][26]=rdm[26][9]=4;
    map[9][32]=map[32][9]=120;//一餐到北区菜鸟驿站120米
    rdm[9][32]=rdm[32][9]=4;
    map[12][26]=map[26][12]=50;//东操到网球场50米
    rdm[12][26]=rdm[26][12]=4;
    map[12][27]=map[27][12]=720;//东操到法学院720米
    rdm[12][27]=rdm[27][12]=8;
    map[13][14]=map[14][13]=20;//海洋科技大楼到教学区20米
    rdm[13][14]=rdm[14][13]=6;
    map[13][17]=map[17][13]=382;//海洋科技大楼到工程学院382米
    rdm[13][17]=rdm[17][13]=6;
    map[13][18]=map[18][13]=475;//海洋科技大楼到材料科学与工程学院475米
    rdm[13][18]=rdm[18][13]=6;
    map[14][15]=map[15][14]=100;//教学区到信北100米
    rdm[14][15]=rdm[15][14]=7;
    map[14][17]=map[17][14]=200;//教学区到工程学院200米
    rdm[14][17]=rdm[17][14]=6;
    map[14][18]=map[18][14]=120;//教学区到材料科学与工程学院120米
    rdm[14][18]=rdm[18][14]=6;
    map[14][19]=map[19][14]=120;//教学区到海洋与大气学院120米
    rdm[14][19]=rdm[19][14]=6;
    map[15][16]=map[16][15]=100;//信北到信南100米
    rdm[15][16]=rdm[16][15]=7;
    map[15][21]=map[21][15]=240;//信北到环境科学与工程学院240米
    rdm[15][21]=rdm[21][15]=6;
    map[16][21]=map[21][16]=240;//信南到环境科学与工程学院240米
    rdm[16][21]=rdm[21][16]=6;
    map[16][23]=map[23][16]=354;//信南到行远楼354米
    rdm[16][23]=rdm[23][16]=6;
    map[16][25]=map[25][16]=365;//信南到图书馆365米
    rdm[16][25]=rdm[25][16]=7;
    map[16][27]=map[27][16]=509;//信南到法学院509米
    rdm[16][27]=rdm[27][16]=7;
    map[17][18]=map[18][17]=168;//工程学院到材料科学与工程学院168米
    rdm[17][18]=rdm[18][17]=12;
    map[17][20]=map[20][17]=187;//工程学院到化学化工学院187米
    rdm[17][20]=rdm[20][17]=12;
    map[18][19]=map[19][18]=17;//材料科学与工程学院到海洋与大气学院17米
    rdm[18][19]=rdm[19][18]=12;
    map[18][20]=map[20][18]=64;//材料科学与工程学院到化学化工学院64米
    rdm[18][20]=rdm[20][18]=12;
    map[18][21]=map[21][18]=114;//材料科学与工程学院到环境科学与工程学院114米
    rdm[18][21]=rdm[21][18]=12;
    map[19][21]=map[21][19]=96;//海洋与大气学院到环境科学与工程学院96米
    rdm[19][21]=rdm[21][19]=12;
    map[20][21]=map[21][20]=34;//化学化工学院到环境科学与工程学院34米
    rdm[20][21]=rdm[21][20]=12;
    map[21][22]=map[22][21]=28;//环境科学与工程学院到地球科学学院28米
    rdm[21][22]=rdm[22][21]=12;
    map[22][23]=map[23][22]=118;//地球科学学院到行远楼118米
    rdm[22][23]=rdm[23][22]=6;
    map[22][25]=map[25][22]=374;//地球科学学院到图书馆374米
    rdm[22][25]=rdm[25][22]=6;
    map[23][24]=map[24][23]=112;//行远楼到行知楼112米
    rdm[23][24]=rdm[24][23]=1;
    map[23][25]=map[25][23]=435;//行远楼到图书馆435米
    rdm[23][25]=rdm[25][23]=9;
    map[25][27]=map[27][25]=301;//图书馆到法学院301米
    rdm[25][27]=rdm[27][25]=9;
    map[25][31]=map[31][25]=285;//图书馆到数学科学学院285米
    rdm[25][31]=rdm[31][25]=6;
    map[26][32]=map[32][26]=50;//网球场到北区菜鸟驿站50米
    rdm[26][32]=rdm[32][26]=4;
    map[27][28]=map[28][27]=50;//法学院到管理学院50米
    rdm[27][28]=rdm[28][27]=12;
    map[28][29]=map[29][28]=50;//管理学院到经济学院50米
    rdm[28][29]=rdm[29][28]=12;
    map[29][30]=map[30][29]=150;//经济学院到外国语学院150米
    rdm[29][30]=rdm[30][29]=12;
    map[30][31]=map[31][30]=100;//外国语学院到数学科学学院100米
    rdm[30][31]=rdm[31][30]=12;
}

/**
* 地点列表
*/
void list()
{
    int i;
    printf("                                                  地点列表");
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
* 输入序号
*/
int fun_number()
{
    int number;
    printf("请输入地点序号：");
    scanf("%d",&number);
    while(number<1 || number>PLACE_SUM)
    {
        printf("地点序号超出范围，请重新输入地点序号：");
        scanf("%d",&number);
    }
    return number;
}

/**
* 输入名称
*/
int fun_name()
{
    int i,number;
    char name[PLACE_NAME_LENGTH];
    printf("请输入地点名称：");
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
            printf("地点名称不存在，请重新输入地点名称：");
            scanf("%s",name);
        }
    }
    return number;
}

/**
* 地点介绍
* 输入序号或名称查询地点信息
*/
void information()
{
    int op=1,number=0;
    while(op!=3)
    {
        printf("*********************************************************\n");
        printf("*\t1.按序号查询\t2.按名称查询\t3.返回上一层\t*\n");
        printf("*********************************************************\n");
        printf("请输入选项：");
        scanf("%d",&op);
        while(op!=1 && op!=2 && op!=3)
        {
            printf("输入错误，请重新输入选项：");
            scanf("%d",&op);
        }
        switch(op)
        {
            case 1:
                number=fun_number();
                printf("\n地点序号：%d\n地点名称：%s\n地点介绍：%s\n\n",number,pla[number].show_name,pla[number].info);
                break;
            case 2:
                number=fun_name();
                printf("\n地点序号：%d\n地点名称：%s\n地点介绍：%s\n\n",number,pla[number].show_name,pla[number].info);
                break;
            case 3:break;
        }
    }
}

/**
* 路线规划
* 迪杰斯特拉算法求最短路径
*/
void guide()
{
    int i,j,u,v,op=0;
    int min=INF,start,end;//最短距离，开始地点序号，结束地点序号
    int path[PLACE_SUM+1]={0},flag[PLACE_SUM+1]={0};//path数组存储路径信息，flag数组存储标志信息（0表示在路径之外，1表示在路径上）
    int path2[PLACE_SUM+1]={0},dis[PLACE_SUM+1];//path2数组存储最短路径，dis数组存储距离信息
    while(op!=3)
    {
        for(i=0;i<=PLACE_SUM;i++)//初始化path数组和flag数组
        {
            path[i]=0;
            flag[i]=0;
        }
        printf("*********************************************************\n");
        printf("*\t1.按序号规划\t2.按名称规划\t3.返回上一层\t*\n");
        printf("*********************************************************\n");
        printf("请输入选项：");
        scanf("%d",&op);
        while(op!=1 && op!=2 && op!=3)
        {
            printf("输入错误，请重新输入选项：");
            scanf("%d",&op);
        }
        switch(op)
        {
            case 1:
                printf("\n开始地点序号\n");
                start=fun_number();
                printf("\n结束地点序号\n");
                end=fun_number();
                break;
            case 2:
                printf("\n开始地点名称\n");
                start=fun_name();
                printf("\n结束地点名称\n");
                end=fun_name();
                break;
            case 3:break;

        }
        if(op==3)
        {
            break;
        }
        for(i=1;i<=PLACE_SUM;i++)//初始化dis数组
        {
            dis[i]=map[start][i];
            if(dis[i]<INF)
                path[i]=start;//可以从开始地点直接到达
        }
        flag[start]=1;//将开始地点的标志设为1
        for(i=1;i<PLACE_SUM;i++)
        {
            min=INF;
            for(j=1;j<=PLACE_SUM;j++)//查找距离开始地点最近的地点
            {
                if(flag[j]==0 && dis[j]<min)
                {
                    min=dis[j];
                    u=j;
                }
            }
            flag[u]=1;//将该地点的标志设为1
            for(v=1;v<=PLACE_SUM;v++)//根据最近地点更新路径
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
        while(path[v]!=start)//从路径数组中找出所需的最短路径
        {
            path2[i++]=path[v];
            v=path[v];
        }
        u=i-1;
        printf("\n路线：");
        printf("%s -> %s -> ",pla[start].name,rd[rdm[start][path2[u]]].name);
        for(j=u;j>=1;j--)
        {
            if(j!=1)
                printf("%s -> %s -> ",pla[path2[j]].name,rd[rdm[path2[j]][path2[j-1]]].name);
            else
                printf("%s -> ",pla[path2[j]].name);
        }
        printf("%s -> %s\n\n",rd[rdm[path2[1]][end]].name,pla[end].name);
    }
}

int main()
{
    int op=0;
    init();
    while(op!=4)
    {
        printf("\n     中国海洋大学崂山校区校园导航系统\n");
        printf("*****************************************\n");
        printf("*\t1.地点列表\t2.地点介绍\t*\n*\t3.路线规划\t4.退出系统\t*\n");
        printf("*****************************************\n");
        printf("请输入选项：");
        scanf("%d",&op);
        while(op!=1 && op!=2 && op!=3 && op!=4)
        {
            printf("输入错误，请重新输入选项：");
            scanf("%d",&op);
        }
        switch(op)
        {
            case 1:list();break;
            case 2:information();break;
            case 3:guide();break;
            case 4:break;
        }
    }
    return 0;
}
