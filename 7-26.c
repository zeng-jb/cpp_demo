#include <stdio.h>
int main()
{
	int a,b,n=0,m=0,x,y;
	scanf("%d %d",&a,&b);
	x=a;y=b;
	do
	{
		n=a%b;
		a=b;
		b=n;
	}while(n!=0);
	m=(x*y)/a;
	printf("%d %d",a,m);
	return 0;
}
