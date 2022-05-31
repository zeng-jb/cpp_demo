#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int shusu (int n);
int main()
{
	int a,b,c;
	scanf("%d",&b);
	if(b>10||b<0)
	return 1;
	for(a=0;a<b;a++){
		scanf("%d",&c);
		if(c<0) return 1;
		if(shusu(c)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
int shusu ( int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
