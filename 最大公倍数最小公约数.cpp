#include <iostream>
using namespace std;
int fcd(int m,int n){
	int t;
	while(n!=0){
		t=m%n;
		m=n;
		n=t;
	}
	return m;
}
int main(){
	int m,n;
	cin>>m>>n;
	int x=fcd(m,n);
	cout<<x<<" "<<m*n/x<<endl;
	return 0;
}
