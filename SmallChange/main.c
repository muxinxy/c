#include <stdio.h>

int first(int k)
{
	if(k==1)	return 1;
	if(k==2)	return 2;
	if(k==3)	return 5;
	if(k==4)	return 10;
	if(k==5)	return 20;
	if(k==6)	return 50;
	return 0;
}

int count_change(int amount,int kindOfCoins)
{
	if(amount==0)	return 1;
	if(amount<0||kindOfCoins==0)	return 0;
	return count_change(amount,kindOfCoins-1)+count_change(amount-first(kindOfCoins),kindOfCoins);
}

int main()
{
    int n;
    printf("money:");
    scanf("%d",&n);
	printf("Solution in all:%d",count_change(n,6));
	return 0;
}
