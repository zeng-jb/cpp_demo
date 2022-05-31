#include <stdio.h>
int main()
{
	int i,j;
	int n,m,max=0;
	int a[101][101]={0},b[101][101]={0}; //a用来初始化，b用来记录座位
	scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&m);
			if(m>max) max=m;
			for(j=0;j<m*10;j++){
				a[i][j]=1;    //初始化 
			}
		}
	int flag=-1;//记录是否同意学校 
	int sum=1;//座位号 
	for(j=0;j<max*10;j++){
		for(i=0;i<n;i++){
			if(a[i][j]){
				if(flag!=i){
					b[i][j]=sum++;
					flag=i;
				}else{
					sum+=1;
					b[i][j]=sum++;
					flag=i;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		printf("#%d\n",i+1);
		for(j=0;j<max*10;j++){
			if(b[i][j]){
				printf("%d%c",b[i][j],(j+1)%10 ? ' ':'\n');
			}
		}
	}
	return 0;	
 } 
