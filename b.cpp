#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int n,k,b[100000];
void init()//ɸѡ������Ԥ����
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
			 for(int j=i*2;j<40000;j+=i)//ÿ�����������������������ı���һ����������
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
}

