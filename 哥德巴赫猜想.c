#include <stdio.h>
#include <math.h> 
int main()
{
	int n=1,i,count;
	int p1,p2;
	while(n!=0){
		scanf("%d",&n);	
		if((n%2==1)||n<4) return 0;
		if(n==0) break;
		p1=1;
		p2=n-p1;
		count=0;
		do{	
				int p1_flag=1;
				int p2_flag=1;
				p1+=1;
				p2=n-p1;
				for(i=2;i<=sqrt(p1);i++){
					if(p1%i==0){
						p1_flag=0;
						break;
					} 
				}
				
				for(i=2;i<=sqrt(p2);i++){
					if(p2%i==0){
						p2_flag=0;
						break;
					} 
				}
			if(p1_flag*p2_flag==1) count++;
		}while(p1<n/2);
			printf("%d\n",count);
   }
   
	return 0;
} 
/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int n,k,b[100000];
void init()//筛选素数的预处理
{
	 for(int i=0;i<40000;i++)
	 {
	 	b[i]=1;
	 }
	 b[0]=b[1]=0;
	 for(int i=2;i<40000;i++)
	 {
		if(b[i])
		{
			 for(int j=i*2;j<40000;j+=i)//每个数的两倍及两倍以上它的倍数一定不是素数
			 {
				b[j]=0;
			}
		 }
	}
}
signed main()
{
 init();
 while(scanf("%lld",&n)&&n)
 {
	 int m=0;
	 for(int i=2; i<=n/2; i++)
	 {
	 	if(b[i]&&b[n-i])
		 {
			 m++;
		 }
	 }
	 printf("%lld\n",m);
 }
 return 0;
}*/
