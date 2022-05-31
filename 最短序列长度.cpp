#include <iostream>
using namespace std;
int main()
{
	int m,n,s;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n>>s;
		int a[n];
		int sum=0;
		int count=2;
		for(int j=0;j<n;j++){
			cin>>a[j];
			sum+=a[j];
		}
		if(sum<s){
			cout<<0<<'\n'<<0<<'\n';
			continue;
		}else{
			if(count==2){
				for(int j=0;j<n-1;j++){
					if((a[j]+a[j+1])>=s){
						cout<<2<<endl<<a[j]<<' '<<a[j+1]<<endl;
						goto out;
					}
				}				
			}
			count++;
				if(count==3){
					for(int z=0;z<n-2;z++){
						if(a[z]+a[z+1]+a[z+2]>=s){
							cout<<3<<endl<<a[z]<<' '<<a[z+1]<<' '<<a[z+2]<<endl;
							goto out;
						}
					}
				}
		}
out:;		
		
	}
	return 0; 
}
