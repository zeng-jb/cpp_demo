#include <stdio.h>
int main()
{
	//初始化
	int price=0,bill=0;
	
	//输入金额和票面
	printf("请输入金额和票面：");
	scanf("%d %d",&price,&bill);
	
	//找零
	if (bill<price)
	{
	printf("对不起，你的钱不够。\n");
    }
    else
	{
	printf("找您%d元。\n",bill-price); 
    }
    
	return 0;
}
