#include <stdio.h>
int main()
{
	int x;
	
	scanf("%d",&x);
	
	int i;
	int  isprime=1;//x������
	
	for(i=2;i<x;i++){
		if(x%i==0){
			isprime=0;
			break;
		}
	} 
	if(isprime==1){
		printf("%d������\n",x);
	}
	else{
		printf("%d��������\n",x); 
	}
	return 0; 
}
