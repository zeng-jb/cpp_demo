#include <stdio.h>
int main()
{
	int i,y,m,d,s=0;
	int a[]{31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d %d",&y,&m,&d);
	if((y%4==0&&y%100!=0)||y%400==0){
		a[1]=29;
	}
	for(i=0;i<m-1;i++){
		s+=a[i];
	}
	printf("%d\n",s+d);
	return 0;
}
