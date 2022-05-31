#include <stdio.h>
int main()
{
	long int x,a[20],n;
	int i,index=-999;
	scanf("%ld%ld",&n,&x);
	for(i=0;i<n;i++){
		scanf("%ld",&a[i]);
		if(a[i]==x) index=i;
	}
	if(index!=-999) printf("%d",index);
	else printf("Not Found");
	return 0;
}
