#include <stdio.h>
int main()
{
	int n,sum=1,month=1,now=1,pre=0;
	scanf("%d",&n);
	
	if(n==sum){
		printf("%d",month);
	}else{
		month++;
		now=sum+pre;
		while (now<n){
			month++;
			pre=sum;
			sum=now;
			now=sum+pre;
		}
	}
	printf("%d",month);
	return 0;
}

