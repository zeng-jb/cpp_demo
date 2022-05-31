#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int a[10]={15,24,2,9,48,63,12,17,99,100};
	/*for(int i=0;i<10;i++){
		cin>>a[i];
	}*/
	sort(a,a+10,cmp);
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
 } 
