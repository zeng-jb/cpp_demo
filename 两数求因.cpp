//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define inf 0x3f3f3f3f
//#define res register int
//const int maxn=1e5;
//int ans=0;
//ll c[maxn];
// 
//ll gcd(ll a,ll b)
//{
//	ll temp1=1,temp2=1;
//	while(temp1){
//		temp1=a%b;
//		temp2=a/b;
//		a=b;
//		b=temp1;
//	}
//	return a;
//}
//int main()
//{
//	ll a,b;
//	scanf("%lld%lld",&a,&b);
//	ll temp=gcd(a,b);
//	c[++ans]=1;
//	ll i=100;	
//	for(i=2;i*i<temp;i++){
//		if(0==temp%i){
//			c[++ans]=i;
//			c[++ans]=temp/i;
//		}
//	}
//	if(1!=temp) c[++ans]=temp;
//	if(i*i==temp) c[++ans]=i;
//	sort(c+1,c+ans+1);
//	for(res i=1;i<=ans;i++){
//		printf("%lld ",c[i]);
//	}
////	printf("\n%d\n",ans);
//	return 0;
//}
#include <IOSTREAM>
#include <MATH.H>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a,ll b){
	ll temp1=1,temp2=1;
	while(temp1){
		temp1=a%b;
		temp2=a/b;
		a=b;
		b=temp1;
	}
	return a;
}

int main(){
	
	ll a,b,n;
	cin>>n;


	for(int j=0;j<n;j++){
		cin>>a>>b;		
		ll temp=gcd(a,b);
	ll ans=1,i;
		for( i=2;i<sqrt(temp);i++){
			if(temp%i==0){
				ans+=2;
			}
		}
		if(temp!=1) ans++;
		if(i==sqrt(temp))ans++;
	
		cout<<ans<<endl;
	}

	return 0;
}

