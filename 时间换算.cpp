#include <stdio.h>

int main()
{
	int utc=0;
	int bjt;
	printf("�����뱱��ʱ��bjt:");
	scanf("%d",&bjt); 
	if(bjt<0||bjt>2359)
	return 0;
	if(bjt/10%10>5)/*����ʮλ���Ƿ����5*/
	return 0;
	if(bjt>800){
		utc=bjt-800;
	}else{
		utc=bjt-800+2400;
	}
	printf("utc=%d\n",utc);
	return 0;
}
