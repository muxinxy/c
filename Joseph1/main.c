#include <stdio.h>
#include <stdlib.h>
#define N 3

int p[201];

  int main()
  {
    int i,m,last,a=0;
    int fun(int m,int p[]);
    printf("Input number:");
    scanf("%d", &m);
    if(m>0&&m<=200){
        last=fun(m,p);
        printf("Last exit person is:%d\n",last);
        // ���ÿ���˳��˵����
        printf("Exit order:\n");
        for (i = m - 1; i >= 0; i --) {
            printf("%d\t", p[i]);
            a++;
            if(a%10==0&&p[i]!=last)printf("\n");

        }
    }
    else printf("error");
    return 0;
  }

  int fun(int m,int p[])
  {
      int i,remain = m,index = 0, flag[201] = {0};
      while (remain >= 1) {
            for (i = 0; i < m; i ++) {
            if (flag[i] == 0) {
                // ����
                index ++;
                // ��p���˳�Ȧ��
                if (index == N) {
                    // �˳�Ȧ��
                    flag[i] = 1;
                    // ���±���
                    index = 0;
              p[remain - 1] = i + 1;
              remain --;
            }
          }
        }
      }
      return (p[0]);
  }
