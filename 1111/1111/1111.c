
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct Student
{
	char name[20];
	double score[3];
	double aver;
};


int main()
{
	int i,j,n;
	struct Student std[30];

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%lf%lf%lf",&std[i].name,&std[i].score[0],&std[i].score[1],&std[i].score[2]);
		std[i].aver=(std[i].score[0] + std[i].score[1] + std[i].score[2])/3;
	}
	//	printf("--------------\n");
	struct Student temp;
	for(i=0;i<n-1;i++){
		for(j=i;j<n;j++){
			if(std[i].aver < std[j].aver){
				temp = std[i];
				std[i] = std[j];
				std[j] = temp;
			}
			else if (std[i].aver == std[j].aver)
			{
				if (strcmp(std[i].name , std[j].name) >0 )
				{
					temp = std[i];
					std[i] = std[j];
					std[j] = temp;
				}
			}
		}
	}

	for(i=0;i<n;i++){

	//	round((std[i].aver * 100.0) / 100);
	((int)(std[i].aver*100+0.5))/100.0;
		printf("%s %.2lf\n",std[i].name,std[i].aver);
	}
	system("pause");
	return 0;
}
