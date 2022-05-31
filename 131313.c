#include <stdio.h>
#include <math.h>
#define PI 3.14159
int main()
{
	double r,h;
	int n=-1;
	double v;
	while(n!=0){
		printf("1-Ball\n\
2-Cylinder\n\
3-Cone\n\
other-Exit\n\
Please enter your command:\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Please enter the radius:\n");
				scanf("%lf",&r);
				v=PI*4/3.0*r*r*r;
				printf("%.2lf\n",v);
				break;
			case 2:	
				printf("Please enter the radius and the height:\n");
				scanf("%lf%lf",&r,&h);
				v=PI*r*r*h;
				printf("%.2lf\n",v);
				break;
			case 3:
				printf("Please enter the radius and the height:\n");
				scanf("%lf%lf",&r,&h);
				v=PI*r*r*h/3.0;
				printf("%.2lf\n",v);
				break;
			default :return 0;
		}
	}
	
} 
