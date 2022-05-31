#include <iostream>
using namespace std;
int main()
{
	int n,i,a[400]={0};
	cin>>n;
	a[0]=1;
	for(i=0;i<n;i++){
		for(int j=0;j<400;j++){
			a[j]*=2;
		}
		for(int j=0;j<400;j++){
			if(a[j]>9){
				a[j+1]+=a[j]/10;
				a[j]%=10;
			}
		}
	}
	for(i=n-1;i>=0;i--){
		if(a[i]==0) n--;
		else break;
	}
	for(i=n-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<endl;
	system("pause");
	return 0;
}
