#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
    double r,h;
    double C,S1,S2,V1,V2;//�������
    printf("������Բ�뾶r��Բ����h��");
    scanf("%lf %lf",&r,&h);//����Բ�뾶��Բ����
    C=2*PI*r;//����Բ�ܳ�
    S1=PI*r*r;//����Բ���
    S2=4*S1;//����Բ������
    V1=4*S1*r/3;//����Բ�����
    V2=S1*h;//����Բ�����
    printf("Բ�ܳ�    =%6.2lf\n",C);
    printf("Բ���    =%6.2lf\n",S1);
    printf("Բ������=%6.2lf\n",S2);
    printf("Բ�����  =%6.2lf\n",V1);
    printf("Բ�����  =%6.2lf\n",V2);//���������
    return 0;
}
