#include <iostream>
using namespace std;
void select(int *p , int n);
int main()
{
	int a[10],i;
	cout<<"输入10个数"<<endl;
	for(i=0;i<10;i++){
		cin>>a[i];
	}
	cout<<endl;
	select(a,10);
	cout<<"排序好的数"<<endl;
	for(i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0; 
}
void select(int *p , int n){
	int i,j,k,t;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(*(p+j)<*(p+k)) k=j;   //xuanzhepaixu		
		}
		t=*(p+k);*(p+k)=*(p+i);*(p+i)=t;
	}
}
