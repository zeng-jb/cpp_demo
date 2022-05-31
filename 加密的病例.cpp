#include <stdio.h>
#include <string.h>
void encrypt(char str[ ],int k);
void onwer(char str[]);
void tranf(char str[]);
int main()
{
    char str[51] ;
    char str2[51];
    int key=3 ;
    while(gets(str)!=NULL)
    {
        encrypt(str, key) ;
        onwer(str); 
        tranf(str);
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
        if (str[i]>='a'&&str[i]<='z')
            str[i]='a'+(str[i]-'a'+key)%26;       
    }
    return;
}
void onwer(char str[]){
	char s[51];
	int len=strlen(str);
	strcpy(s,str);	
	for(int i=len-1;i>=0;i--){
		str[len-i-1]=s[i];
	}

//	printf("%s \n",str);
    return;
}
void tranf(char str[]){
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z')
	       		str[i]+=32;
		else str[i]-=32;
	}
}

/*#include <stdio.h>
#include <string.h>
int main(){
         char str[100];
         gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='a'&&str[i]<='z')
	       		str[i]-=32;
		else if(str[i]>='A'&&str[i]<='Z')
	       		str[i]+=32;
	}

puts(str);
   return 0;

}*/
