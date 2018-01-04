/*********************************
*time:    2016.09.17 22:50
*version:1.0
*********************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define UP   0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define HIGH  35
#define WIDTH 80   //����Ϊż��

int temp[HIGH][WIDTH];//�������飬���ڴ�ӡͼ�Σ��ߡ�ʳ��ո�

int STATE = LEFT;//��ʼ״̬Ϊ������

int FOODPOS = 700; //WIDTH*HIGH/2+WIDTH/2-WIDTH*HIGH/4;//ʳ��ĳ�ʼλ��

#define INIT_LEN 1  //��ʼ�ߵĳ���
int init_pos[INIT_LEN] = {HIGH/2*WIDTH+WIDTH/2};//�ߵĳ�ʼλ��
int SCORE = 0;//�÷�

//�ߵĽṹ��
struct Item{
    int pos;//λ��
    int state;//״̬����������
    struct Item *per, *next;
};

struct Item *head, *tail, *iTemp;

char symbol = '@';//Ԫ�ط���

//��ȡԪ�ص�λ��
int getPos(int pos, int state){
    if(state == UP)
        pos -= WIDTH;
    else if(state == DOWN)
        pos += WIDTH;
    else if(state == LEFT)
        pos -= 2;
    else if(state == RIGHT)
        pos += 2;
    else
    {
        printf("\n״̬state����");
        exit(-1);
    }
    return pos;
}

//�����ߵ�λ����״̬
void change(){
    void print();
    while(1){
        print();
        iTemp = tail;
        while(iTemp != head){
            iTemp->state = iTemp->per->state;//��ǰԪ�ص�״̬������ǰ����״̬
            iTemp->pos = getPos(iTemp->pos,iTemp->state);//����λ����Ϣ
            iTemp = iTemp->per;
        }
        head->state = STATE;
        head->pos = getPos(head->pos, head->state);
    }
}

//��ӡͼ��
void print(){
    int h, w;
    for(h = 1; h < HIGH-1; h++)//��ʼ����������
        for(w = 1; w < WIDTH-1; w++)
            temp[h][w] = 0;
    for(w = 0; w < WIDTH; w += 2){//�õ�0�к����һ��Ϊ2
        temp[0][w] = 2;
        temp[HIGH-1][w] = 2;
    }
    for(h = 0; h < HIGH; h++){//�õ�0�к����һ��Ϊ2
        temp[h][0] = 2;
        temp[h][WIDTH-1] = 2;
    }

    iTemp = head->next;
    while(iTemp){
        h = iTemp->pos / WIDTH;
        w = iTemp->pos % WIDTH;
        temp[h][w] = 1;
        iTemp = iTemp->next;
    }

    h = head->pos / WIDTH;
    w = head->pos % WIDTH;
    int i;
    if(temp[h][w] == 2 || temp[h][w] == 1){//ײ��ǽ���Լ�����Ϸ����head->pos < 0 || head->pos > HIGH*WIDTH
        for(i = 0; i < (WIDTH-12)/2; i++)
            printf(" ");
        printf("��Ϸ����:%d��", SCORE);
        getchar();
        exit(0);
    }
    else
        temp[h][w] = 1;

    temp[FOODPOS/WIDTH][FOODPOS%WIDTH] = 1;
    if(head->pos == FOODPOS){
        //��ʳ��
        struct Item *new = (struct Item*)malloc(sizeof(struct Item));
        new->next = head;
        head->per = new;
        //head = new;
        new->per = NULL;
        new->pos = getPos(head->pos, head->state);
        new->state = head->state;
        head = new;
        SCORE += 10;

        //������ʳ��
        while(temp[FOODPOS/WIDTH][FOODPOS%WIDTH] == 1 || temp[FOODPOS/WIDTH][FOODPOS%WIDTH] == 2 || FOODPOS % 2 ==1){
            FOODPOS = rand() % (HIGH * WIDTH);
        }
        temp[FOODPOS/WIDTH][FOODPOS%WIDTH] = 1;
    }


    //��������ӡͼ��
    system("cls");
    printf("a w s d ���Ʒ���\n");
    for(h = 0; h < HIGH; h++)
        for(w = 0; w < WIDTH; w++){
            if(temp[h][w] == 0)
                printf(" ");
            else if(temp[h][w] == 1)
                printf("%c", symbol);
            else if(temp[h][w] == 2)
                printf("*");
            else{
                printf("\t\t\t\t\t error!");
                exit(-2);
            }
        }
}

//��ʼ���ṹ��
void init(){
    int i;

    head = (struct Item*)malloc(sizeof(struct Item));
    head->per = NULL;
    iTemp = head;
    iTemp->pos = init_pos[0];
    iTemp->state = LEFT;

    for(i = 1; i < INIT_LEN; i++){
        iTemp->next = (struct Item*)malloc(sizeof(struct Item));
        iTemp->next->per = iTemp;
        iTemp = iTemp->next;
        iTemp->pos = init_pos[i];
        iTemp->state = LEFT;
    }

    iTemp->next = NULL;
    tail = iTemp;
}

DWORD WINAPI Thread1(LPVOID pM){
    while(1){
        change();
    }
    return 0;
}

DWORD WINAPI Thread2(LPVOID pM){
    char c;
    while(1){
        c = _getch();//�����ߵ��н�����
        if(c == 'a' && STATE != RIGHT)
            STATE = LEFT;
        else if(c == 'd' && STATE != LEFT)
            STATE = RIGHT;
        else if(c == 'w' && STATE != DOWN)
            STATE = UP;
        else if(c == 's' && STATE != UP)
            STATE = DOWN;
        else
            continue;
    }
    return 0;
}

int main(void) {
    system("mode con cols=80 lines=40");//���ô��ڴ�С
    system("color 8f");//���ô�����ɫ
    init();

    HANDLE handle1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);//�߳�1
    HANDLE handle2 = CreateThread(NULL, 0, Thread2, NULL, 0, NULL);//�߳�2

    WaitForSingleObject(handle1, INFINITE);
    WaitForSingleObject(handle2, INFINITE);
    return 0;
}
