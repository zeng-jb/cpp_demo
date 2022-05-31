#include <stdio.h>
int main()
{
	int x;
	
	scanf("%d",&x);
	
	int i;
	int  isprime=1;//x是素数
	
	for(i=2;i<x;i++){
		if(x%i==0){
			isprime=0;
			break;
		}
	} 
	if(isprime==1){
		printf("%d是素数\n",x);
	}
	else{
		printf("%d不是素数\n",x); 
	}
	return 0; 
}
