#include <stdio.h>
int main()
{
	int n,i,x,a[10];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	a[n]=x;int j;
	for(i=0;i<=n;i++){
		for(j=i;j<n;j++){
			int t;
		if(a[j]>a[j+1]){
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			}
		}
	}
	for(i=0;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
