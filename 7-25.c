#include <stdio.h>
int main()
{
	int number,count=0;
	scanf("%d ",&number);
		if(number%2==1){
			count+=number;
		}
			while(number>0){
				scanf("%d ",&number);	
			if(number%2==1){
				count+=number;
				}
			}
			printf("%d",count);
	return 0;
}
