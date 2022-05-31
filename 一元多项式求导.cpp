#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int a[100];
	int i=0;
	while(scanf("%d",&a[i++])!=EOF);
	int flag=0,j=0;
	while(j+1<i){
		if(flag!=0&&a[j+1]!=0)cout<<" ";
		if(a[j]!=0&&a[j+1]==0);
		else if(a[j]==0)cout<<0<<" "<<0;
		else cout<<a[j]*a[j+1]<<" "<<a[j+1]-1;
		j+=2;
		flag=1;
	} 
    cout<<endl;
	return 0;
}
