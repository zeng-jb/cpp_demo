#include <stdio.h>
int main()
{
	int n,a[10][10]={0};
	int i=0,j=0,t=1;
	scanf("%d",&n);
		a[i][j]=t;	
	while(n*n!=t){
		 while(j+1<n && !a[i][j+1] )
		     a[i][++j] =++t;
		while(i+1<n  && !a[i+1][j])
		     a[++i][j] =++t;
		while(j-1>=0  && !a[i][j-1])
		     a[i][--j] =++t;
		while(i-1>=0 && !a[i-1][j])
		     a[--i][j] =++t;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",a[i][j]);
			if(j==n-1)	printf("\n");
		}
	}
	return 0;
}
