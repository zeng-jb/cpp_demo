#include <stdio.h>
int shu(int n);
int main()
{
	int n,p;
	scanf("%d",&n);
		if(n>=10) return 1;
	p=shu(n);
	printf("%d\n",p);
	return 0;
}
int shu(int n)
{
	int m;
	if(n==1) return 1;
	else{
		m=n*shu(n-1);
	}
	return m;
}
