	#include <stdio.h>
	struct student{
		char name[11];
		char number[6];
		int score;
	}stu[10];
	int main()
	{
		int n,i;
		int sum=0;
		struct student stu[100];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s %s %d",&stu[i].number,&stu[i].name,&stu[i].score);
			sum+=stu[i].score;

		}
		double avg=sum/n;
		printf("%.2lf\n",avg);
		for(i=0;i<n;i++){
			if(stu[i].score<avg)
				printf("%s %s\n",stu[i].name,stu[i].number);	
		}
		return 0;
} 
