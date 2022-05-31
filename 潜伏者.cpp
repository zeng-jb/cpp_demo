#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str1[101],str2[101],str3[101];
	gets(str1);
	gets(str2);
	gets(str3);
	
	int i,j;
	int len1=strlen(str1);
		if(len1<26){
			cout<<"Failed"<<endl;return 0;
		}
	for(i=0;i<len1;i++){
		for(j=0;j<len1;j++){
			if(str1[i]==str1[j]&&str2[i]!=str2[j]){
				cout<<"Failed"<<endl;
				return 0;
			}
		}
	}
	int len2=strlen(str3);
	int index=0;
	for(i=0;i<len2;i++){
		for(j=0;j<len1;j++){
			if(str3[i]==str1[j]){
				cout<<str2[j];
				index=1;
				break;
			}
			if(index==0&&j==len1){
				cout<<"Failed"<<endl;
				return 0;
			}
		}
	}
	return 0;
 } 
