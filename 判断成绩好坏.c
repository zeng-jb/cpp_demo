#include <stdio.h>
#include <string.h>
int main()
{
	char a[31];
	int i,l;
	fgets(a,31,stdin);
	l=strlen(a);
	for(i=0;i<l-1;i++){
		if(a[i]>='a'&&a[i]<='z') a[i]-=32;
		else if(a[i]>='A'&&a[i]<='Z') a[i]+=32;
	}
	for(i=0;i<l-1;i++){
        if(a[i]=='#') return 0;
		putchar(a[i]);
	}
	//puts(a);
	return 0;
}
