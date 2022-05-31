#include <stdio.h>
#include <math.h>
int main()
{
    long int x1,x2,y1,y2;
	int n,i,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
		sum=labs(x1-x2)+labs(y1-y2);
		printf("%d\n",sum);
		if(sum%2==0&&sum!=0){
			printf("Bronya\n");
		}else{
			printf("Seele\n");
		}
	}
	return 0;
 } 
