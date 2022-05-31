#include <iostream>
using namespace std;
int main(){
	int a[50],i,j,n;
	int *p;
	cin>>n;
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	p=a;
	int m=0;
	i=0;j=0;
	while(m<n-1){
		if(*(p+i)!=0) j++;
		
		if(j==3){
			*(p+i)=0;
			j=0;
			m++;
		}
		
		i++;
		
		if(i==n) i=0;
	}
	for(i=0;i<n;i++){
		if(*(p+i)!=0){
			cout<<*(p+i)<<endl;
			break;
		}
	}
	
	return 0;
} 
