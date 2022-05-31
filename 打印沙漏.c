#include<stdio.h>
#include<stdlib.h>
int main()
{	
	char z;
	int n = 1,m,sum=1,a=3;
	int i, j;
	scanf("%d %c", &m,&z);
//m=19 ;z='*';	
	if(m<7){
		printf("%c\n%d\n",z,m-1);
	}else{
			do{
				sum+=a*2;
				a+=2;
				n++;
			}while(m-sum>=a*2);
			n=2*n-1;

	for (i = 0; i < (n+1)/2; i++) //printf("%d %d %d\n",sum,n,m-sum);  //判断最大构成沙漏数； 	//打印上半部分（倒三角）
	{
		for (j = 0; j <i; j++)
		{
			printf(" ");	//打印前面的连续空格
		}
		for (j = 0; j <n-i*2; j++)
		{
			printf("%c",z);		//打印*
		}
		printf("\n");
	}	

	for (i = 1; i < (n / 2) +1; i++)	//打印下半部分（正三角）
	{
		for (j = 1; j <=n / 2-i; j++)	//打印前面的连续空格
		{
			printf(" ");
		}
		for (j = 1; j <= 2 * i+1 ; j++)
		{
			printf("%c",z);		//打印*
		}
		printf("\n");
	}
	printf("%d\n",m-sum);
}
//	system("pause");
	return 0;
}
