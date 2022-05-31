#include <stdio.h>
int main()
{
	int i,sum,n=0;
	char op='0';
	scanf("%d",&sum);
	while (op!='='){
		scanf("%c",&op);
		if(op=='='){
			break;
		}
		scanf("%d",&i);
		if(op=='+'){
			sum+=i;
		}else if(op=='-'){
			sum-=i;
		}else if(op=='*'){
			sum*=i;
		}else if(op=='/'){
			if(i==0){
				n=1;
			}else{
				sum/=i;
			}	
		}
		else{
			n=1;
		}
	}
	if(n==1){
		printf("ERROR\n");
	}else{
		printf("%d\n",sum);
	}
	return 0;
}

