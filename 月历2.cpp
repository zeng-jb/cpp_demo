#include <stdio.h>
int main()
{
	int y=2000,m=01,d=01;
	char w[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	long int i,j,sum=0;
	const int week=7;//2000年1月1号是星期六 
	for(;sum!=-1;){
		
		scanf("%ld",&sum); if(sum==-1) return 0;
		long int sum1;
			for(sum1=sum;sum1>365;sum1-=365){   //判断年份 
				y++;	
				if((y%4==0&&y%100!=0)||y%400==0) sum1--;   //如果闰年多减1天 
			}
		int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			//	if((y%4==0&&y%100!=0)||y%400==0)	a[1]=29;
		int b=0;
			while(sum1>=a[b]){
				sum1=sum1-a[b++];
				m++;      //判断月份 
			};
//			printf("%d\n",sum1);
		d=sum1;	//判断日 
		j=sum%7+week;   //判断星期 
		if(j>7) j%=7;
		printf("%4d-%02d-%02d %s\n",y,m,d,w[j-1]);
		y=2000;m=01;d=01;
	} 
	return 0;
} 
