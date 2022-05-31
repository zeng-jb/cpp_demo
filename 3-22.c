#include <stdio.h>
int main()
{
	int i,n;
	int max=-10000 ,c;
	int a[10];
	scanf("%d\n",&n);
	if(n<=1||n>10) return 1;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
		for(i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
			c=i;
		}
	}
	printf("%d %d",max,c);
	return 0;
}
