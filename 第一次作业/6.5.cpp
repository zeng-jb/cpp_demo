#include <iostream>
using namespace std;
int main()
{
	/*int a[10],i;        //���鷽�� 
	for(i=0;i<10;i++){
		cin>>a[i];
	}
	cout<<endl;
	for(i=0;i<10;i++){
		//cout<<a[i]<<" ";
		cout<<*(a+i)<<" ";   //ָ����� 
	}
	cout<<endl;*/
	
	//ָ�����
	int a[10],i;
	int *p=a;  //ָ��a[0]�� 
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
