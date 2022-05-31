#include <iostream >
using namespace std;
void swap(int *i,int *j){
	int t;
	
	cout<<i<<endl<<j<<endl;
	t=*i;
	*i=*j;
	*j=t;
}
int main()
{
	int i=10,j=20;
	cout<<&i<<endl<<&j<<endl;
	
	swap(&i,&j);
	cout<<i<<" "<<j<<endl;
	
	cout<<swap<<endl;
}
