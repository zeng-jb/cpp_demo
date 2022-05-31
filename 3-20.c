#include <stdio.h>
int main()
{
	int sn=0,i,n,an;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		an+=6*i;
		sn+=an;
	}
	printf("%d\n",sn);
	return 0;
}
