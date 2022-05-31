#include <stdio.h>
#include <math.h>
int main()
{
	unsigned long long int sum=1;
	int i,b=0,a[100];
	for(i=0;i<100;i++){
		scanf("%d",&a[i]);	
		b++;
		if(a[i]==0) break;
	}
//	printf("%d\n",b);
	 for(i=0;i<b-1;i++){
//	 	printf("%d ",a[i]);
		 	for(;a[i]>1;a[i]--)
			{
				sum=sum*a[i]+1;
				sum%=1000000007;
			}
			printf("%llu\n",sum);
			sum=1;
	 }
	return 0;
}
