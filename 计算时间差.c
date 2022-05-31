#include <stdio.h>
int main()
{
	int hour1,minute1;
	int hour2,minute2;
	
	printf("请输入两个时间："); 
	
	scanf("%d %d",&hour1,minute1);
	scanf("%d %d",&hour2,minute2);
	
	int t1=60*hour1+minute1;
	int t2=60*hour2+minute2;
	
	int t=t2-t1;
	
	printf("时间差为%d小时%d分钟",t/60,t%60);
	
	return 0;
}
