#include <stdio.h>
int main()
{
	int v;
	scanf("%d",&v);
	if(v>=1&&v<=500){
		if(v>60){
			printf("Speed: %d - %s\n",v,"Speeding");
		}else{
			printf("Speed: %d - %s\n",v,"OK");
		}
	}
	return 0;
}
