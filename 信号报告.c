#include <stdio.h>

int main()
{
	int x=0;
	int r=x/10,s=x%10; 
	printf("ÇëÊäÈëRSÐÅºÅ£º");
	scanf("%d",&x);
	if(x>59||x<11)
	return 0;
	if(x%10==0) 
	return 0;
	
	if(r=1)
	{printf("Unreadable");} 
	else 
	{printf("Barely readable,occasional words distinguishable");}
	
	
	return 0; 
}
