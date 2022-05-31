#include <stdio.h>
int main()
{
	int i,kg;
	float p;
	
	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
	
	for(i=1;i<=5;i++){
		scanf("%d",&kg);
	if(kg==0) break;
			switch (kg){
				case 1:p=3.00;break;
				case 2:p=2.50;break;
				case 3:p=4.10;break;
				case 4:p=10.20;break;
				default:p=0;break;
			}
		
		printf("price = %0.2f\n",p);
	}
	
	return 0;
}
