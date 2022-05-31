#include <stdio.h>
int main()
{
	int a,b,c,d;
	float v;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	printf("Sum =%d;",a+b+c+d);
	v=(a+b+c+d)/4.0;
	printf(" Average =%0.1f",v);
	return 0;
}
