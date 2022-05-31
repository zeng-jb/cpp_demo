#include <stdio.h>
int main()
{
	char c1='a',c2='b';
	c1-=('a'-'A');
	c2-=('b'-'B');
	printf("%c %c",c1,c2);
	return 0;
}
