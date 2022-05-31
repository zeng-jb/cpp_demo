#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string ch1,ch2;
	float a;
	int count=0;
	cin>>a>>ch1>>ch2;
	cout<<ch1<<endl<<ch2;
	int len=sizeof(ch1);
	for(int i=0;i<len+1;i++){
		if(strcmp(ch1[i],ch2[i])) count++;
	}
	cout<<count<<endl;
	float b=count/len*1.0;
	cout<<b;
	return 0;
}
