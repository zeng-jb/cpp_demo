#include <stdio.h>
int main()
{
	int number,n=0,count=0;
	scanf("%d",&number);
	do
	{
		n+=number%10;
		count++;
		number/=10; 
	}while(number>0);
	printf("%d %d",count,n);
	return 0;
}
