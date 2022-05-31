#include <stdio.h>
int main()
{
	int score,n;
	scanf("%d",&score);
	if(score>100||score<0){
		return 1;
	}
	n=score/10;
	switch(n){
		case 10:
		case 9:printf("A");break;
		case 8:printf("B");break;
		case 7:printf("C");break;
		case 6:printf("D");break;
		default:printf("E");break;
	}
	return 0;
}
