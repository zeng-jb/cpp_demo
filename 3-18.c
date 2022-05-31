#include <stdio.h>
int main()
{
	long int n,count=0;
	double s=0,h,high;
	scanf("%lf%ld",&high,&n);
	s=high*1.0;
	if(n!=0){
		if(n==1){
			printf("%0.1lf %0.1lf",s,s/2.0);
		}else{
			do{
				high*=0.5;
				s+=high*2.0;
				count++;
				if(count==n){
					h=high;
				}
			}while(high!=0);
	printf("%.1lf %.1lf\n",s,h);
		}
	}else{
		printf("0.0 0.0");
	}
	return 0;
}
