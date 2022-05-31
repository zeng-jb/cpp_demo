#include <stdio.h>
int main()
{
	int d;
	scanf("%d",&d);
	if(d>=1&&d<=7){
		d=d+2;
		if(d>7){
			d=d-7;
		}
	}
	printf("%d",d);
	return 0;
}
