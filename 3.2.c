#include <stdio.h>
int main()
{
	int count,score,i;
	int n,A=0,B=0,C=0,D=0,E=0;
	scanf("%d\n",&count);
	for (i=0;i<count;i++){
		scanf("%d",&score);
		while(score>0&&score<=100){
			n=score/10;
			if(n>=9) A++;
			else if(n==8) B++;
			else if(n==7) C++;
			else if(n==6) D++;
			else if(n<6)  E++;
		}
	}
	printf("%d %d %d %d %d\n",A,B,C,D,E);
	return 0;
}
