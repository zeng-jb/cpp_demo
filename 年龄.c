#include <stdio.h>
int main()
{
	int year=0;
	const int MINOR=35;
	
	printf("�������������:");
	scanf("%d",&year);
	
	printf("���������%d�ꡣ\n",year);
	
	if(year<MINOR)
	{ 
	printf("���������õ�,");
	}
	printf("�����������ľ������磬�ú���ϧ�ɡ�\n");
	
	return 0;
}
