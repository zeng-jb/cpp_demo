#include <stdio.h>
int main()
{
	printf("��ֱ�������ߵ�Ӣ�ߺ�Ӣ��:"
	"������5/7��ʾ5Ӣ��7Ӣ��");
	
	double foot;
	double inch;
	
	scanf("%lf %lf",&foot,&inch);
	printf("�����%f�ס�\n",((foot+inch/12)*0.3048));
	return 0;
 } 
