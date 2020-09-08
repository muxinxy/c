#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Word //����һ���ṹ�壬�ֱ�洢���ʺͶ�Ӧ���ʵĸ���
{
    size_t time;
    char word[23000000];
};


void Copy(struct Word *array, FILE *read, const int length);
void Count_for_word(struct Word *array, const int length);

// ����һ
void Copy(struct Word *array, FILE *read, const int length) //�ú����������ǰ��ı��еĵ��ʸ��Ƶ�������
{

    char ch, word[23000000];
    int i = 0, j;

    while (fscanf(read, "%s", &word) != EOF)
    {
        strcpy(array[i].word, word); // ��word���Ƶ�arra[i]��
        ++i;                         //�ƶ�������±�
    }
    fclose(read);                  // �ر��ļ�ָ��
    Count_for_word(array, length); // �����Զ��庯��
}

// ������
void Count_for_word(struct Word *array, const int length) //ͳ�Ƶ��ʵĸ���
{
    int i, j;

    for (i = 0; i < length; i++)
    {
        array[i].time = 1;
        for (j = i + 1; j < length; j++)
        {
            if (strcmp(array[i].word, array[j].word) == 0)
            {
                ++array[i].time;            //���������ͬ�ĵ��ʣ��Ͱ���Ӧ�Ľṹ�岿������ 1
                strcpy(array[j].word, " "); //���Ѹõ�����Ϊ�գ���Ϊ�Ѿ���ȡ���������ˣ���������ı������������ݣ���Ӱ���ı�����
            }
        }
    }

    printf("the file have %d word\n\n", length);

    for (int index = 0; index < length; index++) // ð������
    {
        for (int temp = 0; temp < length - index-1; temp++)
        {
            // ���磺length = 5
            if (array[temp].time < array[temp + 1].time)
            {
                struct Word word = array[temp];
                array[temp] = array[temp + 1];
                array[temp + 1] = word;
            }
        }
    }


    for (i = 0; i < length; i++)
        if (strcmp(array[i].word, " ") != 0)
        { // �������ʱ��
            //printf("%-5s occurrs  %-3d %s\n", array[i].word, array[i].time, ((array[i].time > 1) ? "times" : "time"));
            printf("%-5s:%-3d\n", array[i].word, array[i].time);
        }
}

int main()
{
    char word[23000000];
    int length = 0, ch;
    FILE *read;
    struct Word *array;

    /*
    if (argc < 2 || argc > 2)
    {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    */
    // ���ı�
    if ((read = fopen("words.txt", "r")) == NULL)
    {
        printf("open file failure\n");
        exit(EXIT_FAILURE);
    }
    //
    while (fscanf(read, "%s", &word) != EOF) //�����Ƿ�����ļ�ĩβ
    {
        ++length; //ͳ���ı��е��ʵĸ���
    }

    rewind(read);                                 //���ļ�ָ����Ϊ�ı���ʼ��λ�ã��������λ��Ϣ
    array = malloc(sizeof(struct Word) * length); // ���ʵĳ��ȶ�̬�����ڴ�
    Copy(array, read, length);                    // �����Զ��庯��

    return 0;
}

