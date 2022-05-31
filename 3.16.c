#include <stdio.h>
int main()
{
	char c;
	printf("输入一个字符：");
	c=getchar();
	if(c<32) printf("是控制字符。\n");
	else if(c>='0'&&c<='9') printf("是数字字符。\n");
	else if(c>='A'&&c<='Z'||c>='a'&&c<='z') printf("是字母。\n");
	else printf("是其他字符。\n");
	return 0; 
}
