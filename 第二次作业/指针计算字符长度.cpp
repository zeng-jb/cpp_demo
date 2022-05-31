#include <iostream>
using namespace std;
int main()
{
	int i,j=0;
	char a[100],*p;
	gets(a);
	i=0;
	p=a;
	while(*(p+i)!='\0'){
		i++;
		j++;
	} 
	cout<<j<<endl;
}
