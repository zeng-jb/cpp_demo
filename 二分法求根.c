#include <stdio.h>
#include <string.h>
int main()
{
	char a[16];
	char b[10];
	int i,j=0;
	for(i=0;i<4;i++)
	{
		gets(a);
		b[j++]=a[0];
		b[j++]=a[1];
	 } 
	 b[j]='\0';
	 puts(b);
	 return 0;
}
