#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	int a[10000];
	int n1,n2;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N);
//	for(int i=0;i<N;i++){
//		cout<<a[i]<<" ";
//	}
	int sum1=0,sum2=0;
	if(N%2==0){
		n1=N/2;	n2=N-n1;
		for(int i=0;i<n1;i++)sum1+=a[i];
		for(int i=n1;i<N;i++)sum2+=a[i];
	
	}
	else{
		if(abs(a[N/2]-a[N/2+1]) > abs(a[N/2+1]-a[N/2+2])){
			n1=N/2;	n2=N-n1;
			for(int i=0;i<n1;i++)sum1+=a[i];
			for(int i=n1;i<N;i++)sum2+=a[i];
		}
		else{
			n1=N/2+1;	n2=N-n1;
			for(int i=0;i<n1;i++)sum1+=a[i];
			for(int i=n1;i<N;i++)sum2+=a[i];
		}
	}
	cout<<"Outgoing #: "<<n2<<endl;
	cout<<"Introverted #: "<<n1<<endl;
	cout<<"Diff = "<<abs(sum1-sum2)<<endl;
}
