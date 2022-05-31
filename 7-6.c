#include <stdio.h>
int main()
{	
	double x,y,b;
	int f,i;
	scanf("%lf",&x);
	//x=x/100.0;
   	y=x/100/0.3048;
   	f=(int)y;
   	//b=y-f;
	b=(y-f)*12;
	i=(int)b;
	printf("%d %d",f,i);
	return 0;
}
