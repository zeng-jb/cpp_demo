#include <stdio.h>
int main()
{
	int num,count=1,n,m;
	m=n;
	scanf("%d",&n);
	do{
		n=n/10;
		count*=10;
	}while (n>0);
	while(m>0){
		num=m%count;
		count/=10;
		printf("%d",num);
		m/=10;
	}
	return 0;
}
