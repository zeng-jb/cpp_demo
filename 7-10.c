#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);

	printf("%d+%d=%d\n",a,b,a+b);
	printf("%d-%d=%d\n",a,b,a-b);
	printf("%d*%d=%d\n",a,b,a*b);
		if(a%b==0){
			printf("%d/%d=%d\n",a,b,a/b);
		}else{
			printf("%d/%d=%0.2f\n",a,b,1.0*a/b);
		}
	return 0;
}
