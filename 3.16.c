#include <stdio.h>
int main()
{
	char c;
	printf("����һ���ַ���");
	c=getchar();
	if(c<32) printf("�ǿ����ַ���\n");
	else if(c>='0'&&c<='9') printf("�������ַ���\n");
	else if(c>='A'&&c<='Z'||c>='a'&&c<='z') printf("����ĸ��\n");
	else printf("�������ַ���\n");
	return 0; 
}
