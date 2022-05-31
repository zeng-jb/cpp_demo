#include <stdio.h>

int main()
{
	int utc=0;
	int bjt;
	printf("请输入北京时间bjt:");
	scanf("%d",&bjt); 
	if(bjt<0||bjt>2359)
	return 0;
	if(bjt/10%10>5)/*计算十位数是否大于5*/
	return 0;
	if(bjt>800){
		utc=bjt-800;
	}else{
		utc=bjt-800+2400;
	}
	printf("utc=%d\n",utc);
	return 0;
}
