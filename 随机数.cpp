#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,seed,a,b,i,s;
	scanf("%d%d%d%d",&n,&seed,&a,&b);
	srand(unsigned(seed));
	for(i=1;i<=n;i++){
		s=rand()%(b-a+1)+a;
		if(i==n) printf("%d\n",s);
	}
	return 0;
}
