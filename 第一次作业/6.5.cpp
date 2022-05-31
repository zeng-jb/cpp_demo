#include <iostream>
using namespace std;
int main()
{
	/*int a[10],i;        //数组方法 
	for(i=0;i<10;i++){
		cin>>a[i];
	}
	cout<<endl;
	for(i=0;i<10;i++){
		//cout<<a[i]<<" ";
		cout<<*(a+i)<<" ";   //指针输出 
	}
	cout<<endl;*/
	
	//指针变量
	int a[10],i;
	int *p=a;  //指向a[0]； 
	for(i=0;i<10;i++){
		cin>>*(p+i);
	}
	cout<<endl;
	for(p=a;p<(a+10);p++){
		cout<<*p<<" ";
	} 
	cout<<endl;
	
	
	
	return 0;
 } 
