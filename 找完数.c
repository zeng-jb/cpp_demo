#include <stdio.h>
#include <math.h>
int main()
{
	int m,n,i,j,k=0,sum=0,a[100],count=0,count0=0;
	scanf("%d%d",&m,&n);
//	m=2;n=30;
	for(i=m;i<=n;i++){
		for(j=1;j<i;j++){
			if (i%j==0){            //判断因子 
				a[k]=j;k++;count++;  //将因子输入到数组 
			}
			
		}
			for(k=0;k<count;k++){
					sum+=a[k];            //对数组中因子求和 
				}
				if(sum==i){
					printf("%d =",i);
					count0++;            //统计完数 
					for(k=0;k<count;k++){
						if(k!=count-1)	printf(" %d +",a[k]);   //遍历数组输出 
						else  printf(" %d\n",a[k]);
					}
				}
			k=0;count=0;sum=0;	//重新定义变量 
	}
			if(count0==0) printf("None");				//判断空集 
	return 0;
}
