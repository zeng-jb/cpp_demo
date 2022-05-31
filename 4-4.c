#include <stdio.h>
#include <math.h>
int main()
{
	
	double x,e=1.0,count0=1.0,k=1.0,count=1.0,g;
	scanf("%lf",&x);
		if(x>5||x<0) return 1;
		
while(count0>0.00001)	{
		count*=k;
		g= pow (x*1.0,k*1.0);
		count0=g/count*1.0;
		e+=count0;
		k++;
	}

	printf("%lf %lf\n",k,g);printf("%lf\n",count0);
	printf("%.4lf\n",e);
	return 0;
}
