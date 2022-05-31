#include <stdio.h>

int main()
{
	int n,count=0;	
	int a,b,c,t,max,min;
	scanf("%d",&n);
	if(n>1000||n<100) return 1;
		do{
			count++;
			
	a=n%10;n/=10;b=n%10;c=n/10;
	if(a>b){
		t=a;a=b;b=t;
	}
	if(a>c){
		t=a;a=c;c=t;
	}
	if(b>c){
		t=b;b=c;c=t;
	}
//	printf("%d %d %d\n",a,b,c);  //输入一个三位数，分别将位数分开，其中a最小，其次b，最大是c。 
	max=c*100+b*10+a;min=a*100+b*10+c;
//	printf("%d %d\n",max,min);	
	t=max-min;
//	printf("%d\n",t);

			printf("%d: %d - %d = %d\n",count,max,min,t);
			n=t;
		}while (t!=495);
	return 0;
}


