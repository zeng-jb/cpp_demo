#include<iostream>
using namespace std;
#define N 20
float sishewuru(float n)
{
return (float)((int)(n*100+0.5))/100;
}
int main()
{
struct student
{
char name[20];
float score1;
float score2;
float score3;
float avgscore;
};
int n;
float max;
cin>>n;
struct student stu1[N],temp;
for(int i=0;i<n;i++)
{
scanf("%s %f %f %f",&stu1[i].name,&stu1[i].score1,&stu1[i].score2,&stu1[i].score3);
stu1[i].avgscore=(stu1[i].score1+stu1[i].score2+stu1[i].score3) /3;
stu1[i].avgscore=sishewuru(stu1[i].avgscore);
}
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
max=stu1[n-i-1].avgscore;
if(stu1[j].avgscore>=max)
{
if(stu1[j].avgscore==max)
{
if(stu1[j].name>stu1[n-i-1].name)
{
temp=stu1[j];
stu1[j]=stu1[n-i-1];
stu1[n-i-1]=temp;
continue;
}
}
temp=stu1[j];
stu1[j]=stu1[n-i-1];
stu1[n-i-1]=temp;
}
}
}
for(int i=n-1;i>=0;i--)
{
printf("%s %.2f\n",stu1[i].name,stu1[i].avgscore);
}
return 0;
}
