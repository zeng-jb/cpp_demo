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
	for(i=0;i<n;i++){    //�������� 
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<n;i++){max=-1;
		for(j=0;j<n;j++){
		if(max<a[i][j]){
			max=a[i][j];
				}		
		}  c[x]=max;x++; //printf("%d\n",max);  �����е����ֵ������ֵ����һ������ 
	}
	
	for(j=0;j<n;j++){min=10;
		for(i=0;i<n;i++){
		if(min>a[i][j]){
			min=a[i][j];
				}
		}  	d[y]=min;y++; //printf("%d\n",min);  �����е���Сֵ������ֵ����һ������
	}
for(x=0;x<n;x++){
	for(y=0;y<n;y++){
		if(c[x]==d[y]) {printf("%d %d\n",x,y);goto out;	}  //�����������飬�ҳ���ͬ�� 
	}
} 
	printf("NONE\n");	out:
	return 0;
}
