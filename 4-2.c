#include <stdio.h>
int main()
{
	int n,i=0,j=0,max=-1,min=10,a[6][6],c[6],d[6],x=0,y=0;
	scanf("%d",&n);
		if(n<1||n>6) return 1;
		if(n==1) {
		scanf("%d",&a[i][j]); 
		printf("0 0");
		return 0;	
		}
	for(i=0;i<n;i++){    //输入数组 
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<n;i++){max=-1;
		for(j=0;j<n;j++){
		if(max<a[i][j]){
			max=a[i][j];
				}		
		}  c[x]=max;x++; //printf("%d\n",max);  给出行的最大值，并赋值给另一个数组 
	}
	
	for(j=0;j<n;j++){min=10;
		for(i=0;i<n;i++){
		if(min>a[i][j]){
			min=a[i][j];
				}
		}  	d[y]=min;y++; //printf("%d\n",min);  给出列的最小值，并赋值给另一个数组
	}
for(x=0;x<n;x++){
	for(y=0;y<n;y++){
		if(c[x]==d[y]) {printf("%d %d\n",x,y);goto out;	}  //遍历两个数组，找出相同的 
	}
} 
	printf("NONE\n");	out:
	return 0;
}
