#include <stdio.h>
#include <math.h>
int main()
{
	int m,n,i,j,k=0,sum=0,a[100],count=0,count0=0;
	scanf("%d%d",&m,&n);
//	m=2;n=30;
	for(i=m;i<=n;i++){
		for(j=1;j<i;j++){
			if (i%j==0){            //�ж����� 
				a[k]=j;k++;count++;  //���������뵽���� 
			}
			
		}
			for(k=0;k<count;k++){
					sum+=a[k];            //��������������� 
				}
				if(sum==i){
					printf("%d =",i);
					count0++;            //ͳ������ 
					for(k=0;k<count;k++){
						if(k!=count-1)	printf(" %d +",a[k]);   //����������� 
						else  printf(" %d\n",a[k]);
					}
				}
			k=0;count=0;sum=0;	//���¶������ 
	}
			if(count0==0) printf("None");				//�жϿռ� 
	return 0;
}
