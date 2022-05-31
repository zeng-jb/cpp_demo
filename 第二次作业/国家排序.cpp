#include <iostream>
#include <string.h> 
using namespace std;
void sort(char s[][10]);
int main()
{
	char s[10][10];
	for(int i=0;i<10;i++){
		cin>>s[i];
	}
	sort(s);
	for(int i=0;i<10;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}
void sort(char s[][10]){
	char *p,t[10];
	p=t;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(strcmp(s[j],s[j+1])>0){
				strcpy(p,s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],p);
			}
		}
	}
}
