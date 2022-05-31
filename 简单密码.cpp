#include <stdio.h>
void encrypt(char str[ ],int k);
int main()
{
    char str[200] ;
    int key=21 ;
    while(gets(str)!=NULL)
    {
        encrypt(str, key) ;
        printf("%s\n", str);
    }
    return 0;
}
void encrypt(char str[ ], int key)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i]>='A'&&str[i]<='Z')
            str[i]='A'+(str[i]-'A'+key)%26;
    }
    return;
}
