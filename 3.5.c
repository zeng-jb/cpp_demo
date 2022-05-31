#include <stdio.h>
int main()
{
	char t;
	t = getchar();
	while(t>='0'&&t<='9'){
		printf("%c ",t);
		t = getchar();
	}
	printf("\n");	
	return 0;
 } 
