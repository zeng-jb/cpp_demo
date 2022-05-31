#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a,int b){
	return a>b;
}
int main(){
	int a[101]={0};
	int b[101];
	int k,i=0;
	cin>>k;
	int k1=k;
	while(k1--){
		cin>>b[i];
		int n=b[i++];
			while(n>1){
				if(n%2) n=(3*n+1)/2;
				else{
					n=n/2;
				}
				a[n]=1;
			}	
	}

	sort(b,b+k,compare);
    int flag=0;
	for(int i=0;i<k;i++){
        if(i!=0&&a[b[i]]!=1&&flag==1)cout<<" ";
		if(a[b[i]]!=1){cout<<b[i];flag=1;}
		
	}
	cout<<endl;
	return 0;
} 

