#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	if(n>0){
		m=1;
	}
	else if(n==0){
		m=0;
	}
	else{
		m=-1;
	}
	printf("sign(%d) = %d",n,m);
	return 0;
}
