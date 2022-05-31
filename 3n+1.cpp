#include <iostream>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	if(n<0)return 0;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	else{
		while(n>1){
			if(n%2) n=(3*n+1)/2;
			else{
				n=n/2;
			}
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
 } 
