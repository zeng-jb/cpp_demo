#include <iostream>
using namespace std;
int n,a,fz[50000],ans[50000]={1,1};
int sum[50000]={0};
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	    for(int j=1;j<=ans[0];j++){
	        ans[j]=ans[j]*i+fz[j];
			fz[j]=0;
	        if(ans[j]>9){
	            fz[j+1]+=ans[j]/10;// 
	            ans[j]%=10;
	            if(j==ans[0]) ++ans[0];//阶乘个数 
	        }
		}
		for(int z=0;z<=ans[0];z++){  //阶乘的和 
			sum[z]+=ans[z];
			
			if(sum[z]>9){
				sum[z+1]=sum[z]/10;
				sum[z]%=10;
			}
		}  
	}
    for(int i=ans[0];i>0;i--) printf("%d",sum[i]);
    printf("\n");
    return 0;
}
