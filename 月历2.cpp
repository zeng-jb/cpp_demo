#include <stdio.h>
int main()
{
	int y=2000,m=01,d=01;
	char w[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	long int i,j,sum=0;
	const int week=7;//2000��1��1���������� 
	for(;sum!=-1;){
		
		scanf("%ld",&sum); if(sum==-1) return 0;
		long int sum1;
			for(sum1=sum;sum1>365;sum1-=365){   //�ж���� 
				y++;	
				if((y%4==0&&y%100!=0)||y%400==0) sum1--;   //���������1�� 
			}
		int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			//	if((y%4==0&&y%100!=0)||y%400==0)	a[1]=29;
		int b=0;
			while(sum1>=a[b]){
				sum1=sum1-a[b++];
				m++;      //�ж��·� 
			};
//			printf("%d\n",sum1);
		d=sum1;	//�ж��� 
		j=sum%7+week;   //�ж����� 
		if(j>7) j%=7;
		printf("%4d-%02d-%02d %s\n",y,m,d,w[j-1]);
		y=2000;m=01;d=01;
	} 
	return 0;
} 
