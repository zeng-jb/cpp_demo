#include <stdio.h>
#include <string.h>
int main ()
{
	char a[30000];
	gets(a);
	int l=strlen(a);
	int i;
	for(i=l-1;i>=0;i--){
		char c;
		if((a[i]=='z'&&a[i-1]=='y')||(a[i]=='y'&&a[i-1]=='x')||(a[i]=='y'&&a[i-1]=='z')||(a[i]=='x'&&a[i-1]=='y')){
			c=a[i];a[i]=a[i-1];a[i-1]=c;
		}
	}
	puts(a);
}
