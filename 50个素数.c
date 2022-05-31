#include <stdio.h>

int main()
{
	int x=1;
	int cut=0;
	
	while(cut<50){
		int i;
		int isprime=1;//xÊÇËØÊý
		for(i=2;i<x;i++){
			if(x%i==0){
			isprime=0;
			break;
		    }
		}
		if(isprime==1){
			cut++;
			printf("%d\t",x);
			if(cut%5==0){
				printf("\n");
			}
		}
		x++; 
	}

	return 0;
}

