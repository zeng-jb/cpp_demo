#include <stdio.h>
int main()
{
	int hour1,minute1;
	int hour2,minute2;
	
	printf("����������ʱ�䣺"); 
	
	scanf("%d %d",&hour1,minute1);
	scanf("%d %d",&hour2,minute2);
	
	int t1=60*hour1+minute1;
	int t2=60*hour2+minute2;
	
	int t=t2-t1;
	
	printf("ʱ���Ϊ%dСʱ%d����",t/60,t%60);
	
	return 0;
}
