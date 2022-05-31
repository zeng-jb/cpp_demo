#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}
void ReadString( char s[] ){
	gets(s);
}
char *search(char *s, char *t){
	int i,j,k=0;
	int slen,tlen;
	char *p=NULL;
	slen=sizeof(s)/sizeof(s[0])-1;
	tlen=sizeof(t)/sizeof(t[0])-1;
		for(i=0;i<slen;i++){
			j=i;
			while(s[j]==t[k]){
				j++;k++;
			}
			if(k>=tlen){
				p=&s[i];
				return p;
			}
			k=0;
		}
		return p;
}
