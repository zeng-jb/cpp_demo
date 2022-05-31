#include <stdio.h>
int max(int x,int y);
int main()
{
	int a,b,m;
	scanf("%d %d",&a,&b);
	m=max(a,b);
	printf("%d\n",m);
	return 0;
}
int max(int x,int y)
{
	int max;
	if(x>y){
		max=x;
	}else{
		max=y;
	}
	return max;
}
