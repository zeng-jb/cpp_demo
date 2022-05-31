#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 


int main()
{
	char str1[501];
	char str2[501];
	float index;
	cin>>index>>str1>>str2;
	
//	puts(str1);
//	puts(str2);
	
	int count=0;
	int len=strlen(str1);
	
	for(int i=0;i<len;i++){
		if(str1[i]!=str2[i]) count++;
	}
	
//	cout<<count<<" "<<len<<endl;
	if(count/len*1.0 <1-index) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
 } 
