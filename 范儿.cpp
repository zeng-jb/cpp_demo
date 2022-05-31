/*#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,count=0,j;
unsigned long int a[100000]={0};
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++){
		j=0;
		while(a[j]!=0){
			a[j]*=i;
				if(a[j]>=10000){
					a[j+1]+=a[j]/10000;
					a[j]%=10000;
					count++;
				}
			j++;
		}
		cout<<j<<endl;

	}
	cout<<count<<endl;
	for(int i=count;i>=0;i--){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
 } */
 #include<cstdio>
int n,a,fz[50000],ans[50000]={1,1};
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	    for(int j=1;j<=ans[0];j++){
	        ans[j]=ans[j]*i+fz[j];
			fz[j]=0;
	        if(ans[j]>9){
	            fz[j+1]+=ans[j]/10;// 
	            ans[j]%=10;
	            if(j==ans[0]) ++ans[0];//½×³Ë¸öÊý 
	        }
		}   
	}
    for(int i=ans[0];i>0;i--) printf("%d",ans[i]);
    printf("\n");
    return 0;
}
