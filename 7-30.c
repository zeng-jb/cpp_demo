#include <stdio.h>
int main()
{
	int n,m,count=1,a;
	scanf("%d",&n);
	if(n<0) { printf("fu ")  ;n*=-1;}
	a=n;
	while (a>9)
	{
		count*=10;
		a/=10;
	}
//	count/=10;
//printf("%d\n",count);
	while(count>0){
	m=n/count;

	switch(m){
		case 0:printf("ling");break;
		case 1:printf("yi");break;
		case 2:printf("er");break;
		case 3:printf("san");break;
		case 4:printf("si");break;
		case 5:printf("wu");break;
		case 6:printf("liu");break;
		case 7:printf("qi");break;
		case 8:printf("ba");break;
		case 9:printf("jiu");break;
		default :printf("fu");break;
	}	
	if(count>9) printf(" ");
	n%=count;
	count/=10;
}
	return 0;
}
