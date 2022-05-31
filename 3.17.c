#include <stdio.h>
int main()
{
	int date ,weekday,original_date=3;
	printf("2010年12月日历\n");
	printf("-----------------------------------\n");
	printf("sun  mon  tue  wed  thu  fri  sat  \n");
	printf("-----------------------------------\n");
	scanf("%d",date);
	if(date<1||date>31){
		printf	("数据输入错误；");
		return 1;
	}
	weekday=(date+original_date-1)%7;

		if(weekday==0) printf("%2d\n",date);
		else if (weekday==1) printf("%7d\n",date);
		else if (weekday==2) printf("%12d\n",date);
		else if (weekday==3) printf("%17d\n",date);
		else if (weekday==4) printf("%22d\n",date);
		else if (weekday==5) printf("%27d\n",date);
		else  printf("%32d\n",date);
		
	return 0;
}
