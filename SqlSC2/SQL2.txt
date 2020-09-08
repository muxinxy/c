#include <stdio.h>
#include <stdlib.h>

EXEC SQL BEGIN DECLARE SECTION;
char HSno[50];
char HCno[50];
int HGrade;
int newGrade;
EXEC SQL END DECLARE SECTION;

EXEC SQL INCLUDE sqlca;

int main()
{
    int count=0;
    char yn;
    printf("Please input Cno:\n");
    scanf("%s",HCno);
    EXEC SQL CONNECT TO ZENGZHE-DESKTOP USER ZengZhe;
    EXEC SQL DECLARE SX CURSOR FOR
    select Sno,Cno,Grade
    from SC
    where Cno=:HCno;
    EXEC SQL OPEN SX;
    for(;;)
    {
        EXEC SQL FETCH SX INTO :HSno,:HCno,:HGrade;
        if(sqlca->sqlcode!=0)
            break;
        if(count++==0)
            printf("\n%-10s %-10s %-10s\n", "Sno", "Cno", "Grade");
        printf("%-10s %-10s %-10d\n", HSno, HCno, HGrade);
    }
    printf("updata grade(y/n)?");
    scanf("%c",&yn);
    while(yn!='Y' && yn!='y' && yn!='N' && yn!='n')
    {
        printf("updata grade(y/n)?");
        scanf("%c",&yn);
    }
    if(yn=='Y' || yn=='y')
    {
        printf("Please input new grade:\n");
        scanf("%d",&newGrade);
        EXEC SQL UPDATE SC
        SET Grade=:newGrade;
        WHERE CURRENT OF SX;
    }
    EXEC SQL CLOSE SX;
    EXEC SQL DISCONNECT;
    return 0;
}
