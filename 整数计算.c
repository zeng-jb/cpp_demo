#include <stdio.h>

struct Student
{
	char name[20];
	float score[3];
	float aver;
};
struct Student std[30];
void inputdate();
void sortdate();
void printdate();
int main()
{
	inputdate();
	sortdate();
	printf("\n");
	printdate();
	return 0;
}
void inputdate(){
	int i,n;
		scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%f%f%f",&std[i].name,&std[i].score[0],&std[i].score[1],&std[i].score[2]);
		std[i].aver=(std[i].score[0] + std[i].score[1] + std[i].score[2])/3;
	}

}
void sortdate(){
	int i,j,n;
 Student temp;
	for(i=0;i<n-1;i++){
		for(j=1;j<n;j++){
			if(std[i].aver < std[j].aver){
				temp = std[i].aver;
				std[i].aver = std[j].aver;
				std[j].aver = temp;
			}
			else if (std[i].aver == std[j].aver)
			{
				if (std[j].name > std[i].name)
				{
					temp = std[i];
					std[i] = std[j];
					std[j] = temp;
				}
		}
	}
}
void printdate(){
	int i,n;
	for(i=0;i<n;i++){
		printf("%s %.2f\n",std[i].name,std[i].aver);
	}
}
