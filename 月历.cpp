#include <stdio.h>
int main()
{
	int y,m,i,j;
	scanf("%d%d",&y,&m);
		int mouth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			if((y%4==0&&y%100!=0)||y%400==0)	 mouth[1]=29;
	
	int w=(y+(y-1)/4-(y-1)/100+(y-1)/400)%7;
	int days=0;
	for(i=0;i<m-1;i++){
		days+=mouth[i];
	}
	w=(w+days)%7;    //计算一年打一个月第一天 
	
	printf("     SUN     MON     TUE     WED     THU     FRI     SAT");
	printf("\n"); 
	for(i=0;i<w;i++) printf("        ");
		for(i=w,j=1;j<=mouth[m-1];i++,j++)
		{
		if(i%7==0&&i!=0) printf("\n");
		printf("%8d",j);
		}
	return 0;
}
