#include <stdio.h>
#include <math.h>
int main()
{
	int n,a[100]={0},i,j=0,x;
	scanf("%d",&n);
	for(x=1;x<=n;x++){
		for(i=2;i<x;i++){
			if(x%i==0) {
				break;
			}else{
				for(j=0;j<n;j++){
					a[j]=x;
				}
			}
		}
}
	for(i=0;i<j;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
