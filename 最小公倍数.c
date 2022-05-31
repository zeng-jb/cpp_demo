#include <stdio.h>
int main()
{
	unsigned long int a[100],m;
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T*2;i++){
		scanf("%lu",&a[i]);
	}
	int j=0;
	for(i=0;i<T*2;i+=2){
		m=a[i+1];
		while(1){
			if(m%a[i+1]==0&&m%a[i]==0){
				printf("Case #%d:%lu\n",i+1,m);
				break;
			}
			m++;
		}
	}
	return 0;			 
}
