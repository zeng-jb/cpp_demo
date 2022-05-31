/*#include <iostream>
using namespace std;
int output(int a[],int num);
int main()
{
	int d,num;
	int a[1000]={0};
	cin>>d;
	for(int i=1;i<=d;i++){
		cin>>num;
		output(a,num);
		
	}
	return 0;
}
int output(int a[],int num){
	int i,digit=0;
	int index=1;
	a[1000]={0};
	while(num!=0){
		a[digit++]=num%2;
		num/=2;
	}
	for(i=0;i<digit;i++){
		//cout<<a[i]<<" ";
		if(a[i]==1){
			if(index!=1) cout<<" ";
			cout<<i;
			index++;
		}
	}
	cout<<endl;
}*/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	int i;
	char a[256];
	gets(a);
	while(a[0]!='#'){
		int t=strlen(a);
		int sum=0;
		for(i=0;i<t;i++){
			if(a[i]!=32)
			sum+=(i+1)*(a[i]-'A'+1);
		}
		cout<<sum<<endl;
		gets(a);
	}
	return 0;
}
