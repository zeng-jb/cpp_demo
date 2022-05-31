#include <stdio.h>
int main()
{
	int x,n;
	scanf("%d",&x);
	n=x/16*10+(x%16);
	printf("%d",n);
	return 0;
}
