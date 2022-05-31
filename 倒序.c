#include <stdio.h>
int main()
{
	printf("请输入一个三位数：");
	int a;
	scanf("%d",&a);
	int b=a/100,c=a/10%10,d=a%10;
	printf("倒序三位数为%d\n",d*100+c*10+b);
	return 0;
	
 } 
