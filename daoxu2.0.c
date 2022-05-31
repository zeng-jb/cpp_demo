#include <stdio.h>
int main()
{
	int x=0;
	scanf("%d",&x);
	
	int a,b,c,ret;
	a=x%10;
	b=x/10%10;
	c=x/100;
	ret=a*100+b*10+c*1;
//	printf("%d %d %d\n",a,b,c);
	printf("%d",ret);
	return 0;
	
}
