#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp1;//写文件指针
FILE *fp2;//读文件指针
FILE *fp3;//读文件指针

typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;//动态分配数组存储赫夫曼树

char **HC; //动态分配数组存储赫夫曼编码表
int *w;//动态分配数组存储权值
char *l;//动态分配数组存储字符

/*
保存输入的字符到文件中
*/
void Save(){
	char ch;
	if((fp1=fopen("huffman_a.txt","w"))==NULL){
		printf("Save failed!\n");
		exit(0);
	}
	printf("Please input letters:\n");
	ch=getchar();
    while (ch!='\n'){
        fputc(ch,fp1);
        ch=getchar();
    }
    fclose(fp1);
    printf("Save successfully!\n");
}

/*
读取文件中的字符并比较
*/
void Print(){
    int flag=1;
    char ch1,ch2;
	if((fp2=fopen("huffman_c.txt","r"))==NULL){
		printf("Open file failed!\n");
		exit(0);
	}
	if((fp3=fopen("huffman_a.txt","r"))==NULL){
		printf("Open file failed!\n");
		exit(0);
	}
	printf("The decoding result:\n");
	ch1=fgetc(fp2);
	ch2=fgetc(fp3);
    while (ch1!=EOF && ch2!=EOF){
        if(ch1!=ch2){
            flag=0;
            printf("Error!\n");
            break;
        }
        printf("%c",ch1);
        ch1=fgetc(fp2);
        ch2=fgetc(fp3);
    }
    printf("\n");
    if(flag){
        printf("Successfully!\n");
    }
    fclose(fp2);
}

/*
统计文件中的字符的权值
*/
int Statistics(){
	int i=0,n=0,tempn;
	char ch1,ch2;
	if((fp2=fopen("huffman_a.txt","r"))==NULL){
		printf("Open file failed!\n");
		exit(0);
	}
	printf("Open file successfully!\n");
	printf("The letter and weight:\n");
	for(ch1=0;ch1<=122;ch1++){
		tempn=0;
		rewind(fp2);
		ch2=fgetc(fp2);
		//printf("%c\n",ch2);
		while(ch2!=EOF){
			if(ch1==ch2){
				tempn++;
			}
			ch2=fgetc(fp2);
		}
		if(tempn!=0){
			n++;
		}
	}
	w=(int *)malloc(n*sizeof(int));
	l=(char *)malloc(n*sizeof(char));
	for(ch1=0;ch1<=122;ch1++){
		tempn=0;
		rewind(fp2);
		ch2=fgetc(fp2);
		while(ch2!=EOF){
			if(ch1==ch2){
				tempn++;
			}
			ch2=fgetc(fp2);
		}
		if(tempn!=0){
			w[i]=tempn;
			l[i]=ch1;
			printf("%c,%d\n",l[i],w[i]);
			//printf("%d\n",w[i]);
			//w++;
			//l++;
			i++;
		}
	}
	fclose(fp2);
	return n;
}

/*
选择parent为0且weight最小的两个结点
*/
void Select(HuffmanTree *HT, int n, int *s1, int *s2){
	*s1=1;
	*s2=1;
	int min=99999;
	int i;
	for(i=1;i<=n;i++)
	{
		if((*HT)[i].parent==0)
		{
			min=(*HT)[i].weight;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if((*HT)[i].parent==0 && min>=(*HT)[i].weight)
		{
			*s1=i;
			min=(*HT)[i].weight;
		}
	}
	min=99999;
	for(i=1;i<=n;i++)
	{
		if((*HT)[i].parent==0 && min>=(*HT)[i].weight)
		{
			if(i==*s1)
				continue;
			*s2=i;
			min=(*HT)[i].weight;
		}
	}
	//printf("s1=%d s2=%d\n",*s1,*s2);
}

/*
Huffman编码
*/
void HuffmanCoding(HuffmanTree *HT, int n){
	if(n<=1)
    {
        printf("n<=1\n");
        return;
    }
	int i,s1,s2,start,c,f;
	int m=2*n-1;
	char *cd;
	//HuffmanTree p;
	HC=(char **)malloc((n+1)*sizeof(char *));
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	*HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=1;i<=n;i++){
		(*HT)[i].weight=w[i-1];
		//printf("i=%d weight=%d\n",i,(*HT)[i].weight);
		(*HT)[i].parent=0;
		(*HT)[i].lchild=0;
		(*HT)[i].rchild=0;
	}
	for(;i<=m;i++){
		(*HT)[i].weight=0;
		(*HT)[i].parent=0;
		(*HT)[i].lchild=0;
		(*HT)[i].rchild=0;
	}
	for(i=n+1;i<=m;++i){
        //printf("i=%d weight=%d\n",i,(*HT)[i].weight);
		Select(HT,i-1,&s1,&s2);
		(*HT)[s1].parent=i;
		(*HT)[s2].parent=i;
		(*HT)[i].lchild=s1;
		(*HT)[i].rchild=s2;
		(*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
		//printf("i=%d weight=%d\n",i,(*HT)[i].weight);
	}
	printf("The huffman codes:\n");
	for(i=1;i<=n;++i){
		start=n-1;
		for(c=i,f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent){
			if((*HT)[f].lchild==c){
                cd[--start]='0';
                //printf("0");
			}
			else{
                cd[--start]='1';
                //printf("1");
			}
		}
		HC[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
		//printf("\n");
		printf("%c=%s\n",l[i-1],HC[i]);
	}
	free(cd);
}

/*
编码
*/
void Encode(int n){
    int i=0;
    char ch1;
    if((fp1=fopen("huffman_b.txt","w"))==NULL){
		printf("Open file failed!\n");
		exit(0);
	}
    if((fp2=fopen("huffman_a.txt","r"))==NULL){
		printf("Open file failed!\n");
		exit(0);
	}
	printf("The encoding result:\n");
	ch1=fgetc(fp2);
	while(ch1!=EOF){
        for(i=0;i<n;i++){
            if(ch1==l[i]){
                fputs(HC[i+1],fp1);
                printf("%s",HC[i+1]);
            }
        }
        ch1=fgetc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n");
	printf("Encode successfully!\n");
}

/*
译码
*/
void Decode(HuffmanTree *HT, int n){
    //int i=0,j;
    //char *cd,ch;
    char ch;
    int m=2*n-1;
    int x=m;
    //cd=(char *)malloc(n*sizeof(char));
    //cd[n-1]='\0';
    if((fp1=fopen("huffman_c.txt","w"))==NULL){
		printf("Open file failed!\n");
		exit(0);
	}
    if((fp2=fopen("huffman_b.txt","r"))==NULL){
		printf("Open file failed!\n");
		exit(0);
	}
	ch=fgetc(fp2);
	while(ch!=EOF){
        /*
        cd[i++]=ch;
        cd[i]='\0';
        for(j=0;j<n;j++){
            if(strcmp(HC[j+1],&cd[0])==0){
                i=0;
                fputc(l[j],fp1);
                //printf("%c",l[j]);
            }
        }
        */
        if(ch=='0'){
            x=(*HT)[x].lchild;
        }
        else{
            x=(*HT)[x].rchild;
        }
        if(x<=n){
            fputc(l[x-1],fp1);
            x=m;
        }
        ch=fgetc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("Decode successfully!\n");
}

int main() {
	int n;
	//WeightArray w;
	//LetterArray l;
	HuffmanTree HT;
	//Save();
	n=Statistics();
	printf("n=%d\n",n);
	HuffmanCoding(&HT,n);
	Encode(n);
	Decode(&HT,n);
	Print();
	free(w);
	free(l);
	free(HT);
	free(HC);
	return 0;
}
