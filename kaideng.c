#include <stdio.h>
int main()
{
	unsigned	long int l,r,a[100000]={0};
	unsigned	long int i,j,count=0;
	scanf("%lu%lu",&l,&r);
	for(i=l;i<=r;i++){
		for(j=1;j<=r;j++){
			if(i%j==0){
				if(a[i-1]==0) a[i-1]=1;
				else a[i-1]=0;
			}
		}
	}
	for(i=l;i<=r;i++){
		if(a[i-1]==1) count++;
	}
	printf("%d",count); 
	return 0;
}
