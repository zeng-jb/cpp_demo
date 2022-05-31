#include <stdio.h>
#define PRICE 3.14
int main()
{
	int num;
	float total;
	scanf("%d",&num);
	total=num*num*PRICE;
	printf("the total is %.2f",total);
	return 0;
}
