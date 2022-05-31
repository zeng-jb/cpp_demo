/*#include <stdio.h>
int main()
{
	int n,a[1001]={0},i=0,j=1,count;
	scanf("%d",&n);
	count=n;
//	for(i=0;i<n;i++) printf("%d ",a[i]);
	while(1){
		if(i==n) i=0;
		if(a[i]==0){
			if(j==3){
				a[i]=1;
				count--;
					if(count==1) goto out;
				i++;j=1;
			}else{
				i++;j++;
			}
		}else{
			i++;
		}
	}
out:
	for(i=0;i<n;i++)
	{
		if(a[i]==0){
			printf("%d\n",i+1);
			return 0;
		}
	}
 } */
 #include <stdio.h>
int main()
{
 int m,i,s=0;
 scanf("%d",&m);
 for(i=1 ; i<=m ; i++)
s = (s+3) % i ;
printf("%d\n",s+1);
 return 0 ;
} 
