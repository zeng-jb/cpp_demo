#include <stdio.h>
int main()
{
	int h;
	float w;
	scanf("%d",&h);
	if(h>100&&h<=300){
		w=(h-100)*0.9*2;
		printf("%0.1f",w);
	}
	return 0;
 } 
