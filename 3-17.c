#include <stdio.h>
int main()
{
	int a,b,n,i;

	scanf("%d %d %d",&a,&b,&n);
 		for( i=0;i<n-1;i++){
 		       a=a*10%b;
	
 		}
 	printf("%d",a*10/b);
	return 0;
}
