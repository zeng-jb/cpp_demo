#include <iostream>
using namespace std;
int main()
{
	int g,m;
	char j;
	cin>>g>>j;
	if(g<=1000) m=8;
	else{
		g-=1000;
		if(g%500!=0&&g/500==0)  m=8+4;
		else if (g%500!=0) m=8+4*(g/500+1);
		else m=8+4*(g/500);
	}
	if(j=='y') m+=5;
	cout<<m<<endl;
	return 0;
}
