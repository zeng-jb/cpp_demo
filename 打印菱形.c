
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	int i, j;
	scanf("%d", &n);
	//��ӡ�ϰ벿�֣������ǣ�
	for (i = 0; i < (n / 2) + 1; i++)
	{
		//��ӡǰ��������ո�
		for (j = 0; j < n / 2-i; j++)
		{
			printf("  ");
		}
		//��ӡ*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
 
	//��ӡ�°벿�֣������ǣ�
	for (i = 0; i < n / 2; i++)
	{
		//��ӡǰ��������ո�
		for (j = 0; j <i+1; j++)
		{
			printf("  ");
		}
		//��ӡ*
		for (j = 0; j <n-(2*i+2); j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
