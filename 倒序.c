#include <stdio.h>
int main()
{
	printf("������һ����λ����");
	int a;
	scanf("%d",&a);
	int b=a/100,c=a/10%10,d=a%10;
	printf("������λ��Ϊ%d\n",d*100+c*10+b);
	return 0;
	
 } 
