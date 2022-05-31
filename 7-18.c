#include <stdio.h>
int main()
{
	int min,fare;
	float s,f;
	scanf("%f %d",&s,&min);
	min=(min/5)*2;
	if(s<=3){
		f=10;
	}
	else if(s>3&&s<=10){
		f=10+(s-3)*2; 
	}
	else if(s>10){
		f=24+(s-10)*3;
	}
	f+=min;
	fare=(int)(f+0.5);
	printf("%d",fare);
	return 0;
}
