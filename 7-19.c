#include <stdio.h>
int main()
{
	int y,m,d,i,date=0;
	scanf("%d/%d/%d",&y,&m,&d);
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((y%4==0&&y%100!=0)||y%400==0){
		a[1]=29;
	}
	for(i=1;i<m;i++){
		date+=a[i];
	}
	printf("%d",date+d);
	return 0;	
}
