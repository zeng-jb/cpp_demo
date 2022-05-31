#include <iostream>
using namespace std;
int main()
{
unsigned long 	int i,m,n,j,a[500000]={1};//用0表示开，1表示关；
long int count=0; 
	cin>>n>>m;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(j%i==0){
				if(a[j-1]==1) a[j-1]=0;
				else a[j-1]=1;
			} 
		}
	}
	for(j=0;j<n;j++){
//		cout<<a[j]<<endl;
		if(a[j]==0) {
			count++;	
		}
	}
	cout<<count;
	return 0;
}
