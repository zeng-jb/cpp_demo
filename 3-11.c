#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,p=1,sum=0,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		p*=i;
		sum+=p;
	}
	printf("%d\n",sum);
	return 0;
}
