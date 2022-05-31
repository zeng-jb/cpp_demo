/*#include <stdio.h>
int main()
{
	int i,j;
	char str[100],str0[100];
	scanf("%s %s",str,str0);
	for(i=0;str[i]!='\0';i++);
		for(j=0;str0[j]!='\0';j++){
			str[i]=str0[j];
			i++;
		}
	
	str[i]='\0';
	printf("%s",str);
	return 0;
}*/
#include <stdio.h>
#include <string.h>
int main()
{
	
	char str[100],str0[100];
	scanf("%s %s",str,str0);
	strcat(str,str0);
	printf("%s\n",str);
	return 0;
}
