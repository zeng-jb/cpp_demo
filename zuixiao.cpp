/*#include <stdio.h>
int main()
{
	unsigned long long int a[100],m;
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T*2;i++){
		scanf("%llu",&a[i]);
	}
	for(i=0;i<T*2;i+=2){
		m=a[i+1];
		while(1){
			if(m%a[i+1]==0&&m%a[i]==0){
				printf("Case #%d:%llu\n",i+1,m);
				break;
			}
			m++;
		}
	}
	return 0;			 
}*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int rem(int a,int b)
{
    int c=a%b;
    //printf("a %d a\n",a);
    //printf("b %d b\n",b);
    //printf("c %d c\n",c);
    if(c==0)
    return b;
    else
   {
    a=b;
    b=c;
    rem(a,b);
   }
}
int mul(int a,int b)
{
        //cout<<"rem"<<rem(a,b)<<"rem"<<endl;
        //printf("%d %d\n",a,b);
        return a/(rem(a,b))*b;//先除后乘，防止溢出，不过为什么改成__int64之后传错值了呢
}
int main()
{
    int s[100];
    int i,j,n,m,t;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
        scanf("%d",&m);
        for(j=0;j<m;j++)
        scanf("%d",&s[j]);
        t=s[0];
        /*for(i=0;i<m;i++)
        printf("m  %d   m\n",s[i]);*/
        for(i=1;i<m;i++)
        {
            //printf("%d gg %d\n",t,s[i]);
            t=mul(t,s[i]);
        }
        cout<<t<<endl;
        }
    }
    return 0;
}

