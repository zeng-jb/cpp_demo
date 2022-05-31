#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int i=0,sum=0,b[4];
	char a[32];

		fgets(a,32,stdin);
		int l=strlen(a);
	int j=0,count=7;
		while(j<l-1){
			sum+=(a[j++]-'0')*pow(2,count--);

			if(count==0){
				b[i++]=sum;
				sum=0;count=7;
			}
		}
		for(i=0;i<4;i++){
			printf("%d",b[i]);	
			if(i<3) printf(".");		
		}
		return 0;
}
