#include <stdio.h>
#include <stdlib.h>

EXEC SQL BEGIN DECLARE SECTION;
char HCno[50];
char HCname[50];
int HCpno;
int HCcredit;
EXEC SQL END DECLARE SECTION;

EXEC SQL INCLUDE sqlca;

int main()
{
    int count=0;
    printf("Please input course name:\n");
    scanf("%s",HCname);
    EXEC SQL CONNECT TO ZENGZHE-DESKTOP USER ZengZhe;
    EXEC SQL DECLARE SX CURSOR FOR
    select Cno,Cname,Cpno,Ccredit
    from Course
    where Cname=:HCname;
    EXEC SQL OPEN SX;
    for(;;)
    {
        EXEC SQL FETCH SX INTO :HCno,:HCname,:HCpno,:HCcredit;
        if(sqlca->sqlcode!=0)
            break;
        if(count++==0)
            printf("\n%-10s %-20s %-10s %-10s\n", "Cno", "Cname", "Cpno", "Ccredit");
        printf("%-10s %-20s %-10d %-10d\n", HCno, HCname, HCpno, HCcredit);
    }
    EXEC SQL CLOSE SX;
    EXEC SQL DISCONNECT;
    return 0;
}
