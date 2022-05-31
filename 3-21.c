#include <stdio.h>
#include <math.h>
int main()
{
	int sn=0,i,m,n,an=0;
	scanf("a=%d n=%d",&m,&n);
	for(i=0;i<n;i++){
		an+=m*pow(10,i);
		sn+=an;
	}
	printf("%d\n",sn);
	return 0;
}
