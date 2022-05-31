#include <Stdio.h>
int main()
{
	int  y,f,n;
	int i,j,k=0;
	scanf("%d",&n);
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(n==98*i-199*j){
				y=j;f=i;k=1;
				goto out;
			}
		}
	}
out:
	if(k==1) printf("%d.%d",y,f);
	else  printf("No Solution");
	return 0;
}
