#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Word //声明一个结构体，分别存储单词和对应单词的个数
{
    size_t time;
    char word[23000000];
};


void Copy(struct Word *array, FILE *read, const int length);
void Count_for_word(struct Word *array, const int length);

// 函数一
void Copy(struct Word *array, FILE *read, const int length) //该函数的作用是把文本中的单词复制到数组中
{

    char ch, word[23000000];
    int i = 0, j;

    while (fscanf(read, "%s", &word) != EOF)
    {
        strcpy(array[i].word, word); // 将word复制到arra[i]中
        ++i;                         //移动数组的下标
    }
    fclose(read);                  // 关闭文件指针
    Count_for_word(array, length); // 调用自定义函数
}

// 函数二
void Count_for_word(struct Word *array, const int length) //统计单词的个数
{
    int i, j;

    for (i = 0; i < length; i++)
    {
        array[i].time = 1;
        for (j = i + 1; j < length; j++)
        {
            if (strcmp(array[i].word, array[j].word) == 0)
            {
                ++array[i].time;            //如果遇到相同的单词，就把相应的结构体部分增加 1
                strcpy(array[j].word, " "); //并把该单词置为空，因为已经读取到数组中了，所以这里改变的是数组的数据，不影响文本数据
            }
        }
    }

    printf("the file have %d word\n\n", length);

    for (int index = 0; index < length; index++) // 冒泡排序
    {
        for (int temp = 0; temp < length - index-1; temp++)
        {
            // 例如：length = 5
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
        { // 当不相等时候
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
    // 打开文本
    if ((read = fopen("words.txt", "r")) == NULL)
    {
        printf("open file failure\n");
        exit(EXIT_FAILURE);
    }
    //
    while (fscanf(read, "%s", &word) != EOF) //测试是否读到文件末尾
    {
        ++length; //统计文本中单词的个数
    }

    rewind(read);                                 //把文件指针置为文本开始的位置，并清除错位信息
    array = malloc(sizeof(struct Word) * length); // 单词的长度动态分配内存
    Copy(array, read, length);                    // 调用自定义函数

    return 0;
}

