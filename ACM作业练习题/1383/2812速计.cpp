/*#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	char ch[256];
	int i;
	gets(ch);
	while (ch[0] != '#') {

	}
}*/
#include<stdio.h>
#include<string.h>
int main()
{
    char ch[256];
    int i;
   // gets_s(ch);
    gets(ch) ;
    while (ch[0] != '#')
    {
        int t = strlen(ch), sum = 0;
        for (i = 0; i < t; i++)
            if (ch[i] != 32)
                sum = sum + (i + 1) * (ch[i] - 'A' + 1);
        printf("%d\n", sum);
      //  gets_s(ch);
        gets(ch) ;
    }
    return 0;
}
