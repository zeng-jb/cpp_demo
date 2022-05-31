#include <iostream>
#include <math.h>
using namespace std; 
int main()
{
	int i,j;
	char n;
	cin >>n;
	for(i=0;i<3;i++){
		for(j=0;j<1-i;j++){
			cout<<' ';
		}
		for(j=0;j<2*i+1;j++){
			cout<<n;
		}
		cout<<'\n';
	}
	return 0;
}
