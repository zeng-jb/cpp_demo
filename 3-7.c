#include <stdio.h>
int main()
{
	long int num;
    int count=0;
	scanf("%ld",&num);

	do {
		count++;
		num/=10;
	}while(num>0);
	printf("%d",count);
	return 0;
}
