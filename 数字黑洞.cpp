#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool cmp(char str1 ,char str2){
	return str1>str2;
}
int main()
{
	char str[5];
	gets(str);
	//cout<<str<<endl;	
	char *s1,*s2;
	int num,a,b;
	while(num!=0||num!=6174){
	
//		sort(str,str+4);
//		cout<<str<<endl;
//		sort(str,str+4,cmp);
//		cout<<str<<endl;
		//s1=str;
		sort(str,str+4,cmp);
		a=(atoi(str));
		//s2=str;
		sort(str,str+4);
		b=(atoi(str));
	//	cout<<s1<<endl<<s2<<endl;
		num=a-b;
	//	str=itoa(num);

		printf("%04d - %04d = %d\n",a,b,num);
		if(num==0||num==6174)break;
		snprintf(str, sizeof(str), "%d", num);
	}

	return 0;
}
