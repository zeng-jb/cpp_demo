#include <iostream>
using namespace std;
int main()
{
	int M,a[10000],L,begin,end;
	cin>>L>>M;
	for(int i=0;i<=L;i++){
		a[i]=0;
	}
	for(int i=0;i<M;i++){
		cin>>begin>>end;
		for(int j=begin;j<=end;j++){
			if(a[j]==0){
				a[j]=1;
			}
		}
	}
	int count=0;
	for(int i=0;i<=L;i++){
		if(a[i]==0) count++;
	}
	cout<<count;
	return 0;
}
