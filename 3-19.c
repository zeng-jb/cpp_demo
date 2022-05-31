#include <stdio.h>
int main()
{
	int i,n;
	int max=-1 ,min=10,c,d;
	int a[10],t;
	scanf("%d",&n);
	if(n<0||n>10) return 1;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
		if(n==2){
				for(i=0;i<n;i++){
				if(max<a[i]){
					max=a[i];c=i;
				}
				if(min>a[i]){
					min=a[i];d=i;
				}
			}
			t=a[c];a[c]=a[d];a[d]=t;
			
		}else if(n==1){

		}
	else{
			for(i=0;i<n;i++){
					if(max<a[i]){
						max=a[i];
						c=i;
					}
					if(min>a[i]){
						min=a[i];
						d=i;
					}
				}
		t=a[0];	a[0]=a[d];	a[d]=t;
		if(c==0){
				t=a[n-1];	a[n-1]=a[d];	a[d]=t;
		}else{
				t=a[n-1];	a[n-1]=a[c];	a[c]=t;
			}
	}
			for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
	return 0;
}
