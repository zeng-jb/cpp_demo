/*#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
int main()
{
	string s1;
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		switch(s1[i]){
			case 'A': cout<<'T';break;
			case 'T': cout<<'A';break;
			case 'C': cout<<'G';break;
			case 'G': cout<<'C';break;
		}
	}
	return 0;
}*/

/*#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char a[31];
	char a0,a1;
	cin>>a;
	cin>>a0>>a1;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]==a0) a[i]=a1;	
	}
	cout<<a<<endl;
	return 0;
}*/

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[81];
	int i;
	cin>>str;
	int len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]=='z') {
			str[i]='a';
			continue;
		}
		if(str[i]=='Z') {
			str[i]='A';	
			continue;
		}
		if(str[i]>='a'&&str[i]<'z'||str[i]>='A'&&str[i]<'Z')
			str[i]+=1;
		if(str[i]=='\0') continue;
	}
	cout<<str;
	return 0;
}



