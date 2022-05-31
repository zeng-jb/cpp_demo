#include <stdio.h>
int main()
{
	int x=0;
	printf("«Î ‰»Î≥…º®£®0-100£©£∫");
	scanf("%d",&x);
	x/=10;
	
	switch (x){
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("F\n");
			break;
	}
	return 0;
 } 
