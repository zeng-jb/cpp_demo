#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
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
				//if (std[i].name (std[j].name) > 0)
				{
					temp = std[i];
					std[i] = std[j];
					std[j] = temp;
				}
		   }
		}
	}
	
/*bool operator<(student a, student b)
{
    if (a.score != b.score)
        return a.score > b.score;
    if (a.name.compare(b.name) <= 0)
        return true;
    else
        return false;
*/

	for(i=0;i<n;i++){
		double m,d;
		int n;
	//	m=std[i].aver*100.0+0.5;std[i].aver=m/100.0;
	//	round(std[i].aver * 100) / 100.0;
	(int)(std[i].aver+0.005);
		printf("%s %.2lf\n",std[i].name,std[i].aver);
	}
	return 0;
}

