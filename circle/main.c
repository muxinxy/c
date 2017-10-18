#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
    double r,h;
    double C,S1,S2,V1,V2;//定义变量
    printf("请输入圆半径r和圆柱高h：");
    scanf("%lf %lf",&r,&h);//输入圆半径和圆柱高
    C=2*PI*r;//计算圆周长
    S1=PI*r*r;//计算圆面积
    S2=4*S1;//计算圆球表面积
    V1=4*S1*r/3;//计算圆球体积
    V2=S1*h;//计算圆柱体积
    printf("圆周长    =%6.2lf\n",C);
    printf("圆面积    =%6.2lf\n",S1);
    printf("圆球表面积=%6.2lf\n",S2);
    printf("圆球体积  =%6.2lf\n",V1);
    printf("圆柱体积  =%6.2lf\n",V2);//输出计算结果
    return 0;
}
