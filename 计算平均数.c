#include <stdio.h>
int main()
{
	int a,b;
	
	printf("请输入两个数：");
	scanf("%d %d",&a,&b);
	double c=(a+b)/2.0;
	printf("两位数的平均值a+b=%f\n",c);
	
	return 0; 
}
