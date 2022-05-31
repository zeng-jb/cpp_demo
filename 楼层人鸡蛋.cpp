#include <iostream>
#define uinimax 10000 
using namespace std;
int dongtai(int m,int k);
int main()
{
	int n,m,k;
	int put;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>k;
		put=dongtai(m,k);
		cout<<put<<endl;
	}
	return 0;
}
int dongtai(int m,int k){
	int i,j;
	int dp[m+1][k+1];
	int temp,max=uinimax;
/*	for(j=0;j<k+1;j++){
		dp[0][j]=0;
		dp[1][j]=j;
	}
	for(i=2;i<m+1;i++){
		dp[i][0]=0;
		dp[i][1]=1;
	}*/
	for(i=0;i<m+1;i++){
		for(j=0;j<k+1;j++){
			int z;
			if(i==0||j==0){
				dp[i][j]=0;
			}else if(j==1) dp[i][1]=1;
			else if(i==1) dp[1][j]=j;
			else{
					for( z=1,max=uinimax; z<j ; z++){
							temp=dp[i][j-z] > dp[i-1][z-1] ? dp[i][j-z] : dp[i-1][z-1];
							max=max < temp ? max : temp; 
						}
						dp[i][j]=max+1;			
			}

			
		}
	}
	for(i=0;i<=m;i++){
		for(j=0;j<=k;j++){
			cout<<dp[i][j]<<" ";
			if(j==k) cout<<endl;
		}
	}
	return dp[i-1][j-1];
}
