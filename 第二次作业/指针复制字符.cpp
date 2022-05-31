#include <iostream>
using namespace std;
int main()
{
	int i,j,m;
	char a[100],b[100];
	char *p1,*p2;
	gets(a);
	cin>>m;
	for(i=0;i<m;i++)
	p1=a;
	p2=b;

	for(i=m,j=0;*(p1+i)!='\0';i++,j++){
		*(p2+j)=*(p1+i);
	}
	*(p2+j)='\0';
	puts(a);
	cout<<endl;
	puts(b);
	return 0;
 } 
