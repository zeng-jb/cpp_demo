#include <stdio.h>
int main()
{
	int x;
	int one,two,five;
	int exit=0;
//	scanf("%d",&x);
	 x=5;
	for(one=1;one<=10*x;one++){
		for(two=1;two<=10*x/2;two++){
			for(five=1;five<=10*x/5;five++)
			if(one+2*two+5*five==10*x){
				printf("可以用%d个一角加%d个两角加%d个五角得到%d元\n",one,two,five,x);
				exit=1;
				break;  //goto out;
			}if(exit==1) break;
		}if(exit==1) break;
	}
	//out:
	return 0;
	
}
