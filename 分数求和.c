#include <stdio.h>
#include <math.h>
fenshu (double f);
main()
{
	int i,j,a,b,n;
	char c;
	double s[100],sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%c%d",&a,&c,&b);
		s[i]=a*1.0/b;
		sum+=s[i];
	}
	int itz=(int)sum;
	double lof=sum-=itz;
	fenshu(lof);
	if(itz!=0) printf("%d ",itz);
	if(lof!=0) printf("%lf",sum);
	return 0;
 } 
fenshu(double lof){
	int fz=(int)(lof*1000),fm=1000;
	int fz1=fz,fm1=fm;
	int r;

    for(r=2;r<=fz;r++)
    {
        //找到公约数
        if(fabs((fz1*1.0/r)-(fm1*1.0/r))<=1e-10)
        {
           fz=fz1/r;
           fm=fm1/r;
           break;
        }
    }
	printf("%d %d\n",fz,fm);
}

/*
#include<stdio.h>
void add(long *num1,long *den1,long *num2,long *den2)
{
    long den1_t=(*den1);
    *den1=(*den1)*(*den2);
    *num1=(*den2)*(*num1)+(den1_t)*(*num2);//上面中den1的值已经改变
}
void simply(long *num1,long *den1)
{
    long i;
    for(i=2;i<*num1;i++)
    {
        //找到公约数
        if(*num1%i==0&&*den1%i==0)
        {
            *num1=*num1/i;
            *den1=*den1/i;
            i=2;
        }
    }
}
int main()
{
    int N,i,flag=0;
    long num1,den1,num2,den2,a;
    scanf("%d",&N);
    scanf("%ld/%ld",&num1,&den1);
    for(i=0;i<N-1;i++) //输入剩余的N-1个值
    {
        scanf("%ld/%ld",&num2,&den2);
        add(&num1,&den1,&num2,&den2);
        if(num1<0)
        {
            flag=1;
            num1=-(num1);//这样分子就为正值，在化简的时候就可以正常使用函数
        }
       simply(&num1,&den1);
       if(flag)
       {
           num1=-num1;
           flag=0;
       }
    }
    //对结果进行处理部分
    a=num1/den1;
    if(num1<0)
    {
        num1=-num1;
        flag=1;
    }
    num1=num1%den1;
    simply(&num1,&den1);//确保化简完全
    //还原
    if(flag)
    {
        num1=-num1;
    }
    if(a)//存在整数部分
    {  if(num1==0) printf("%d",a);//结果只有整数部分
       else printf("%d ",a);//注意结果严格控制空格
    }
    if(num1!=0)
    {
        printf("%d/%d",num1,den1);
    }
    if(num1==0&&a==0) printf("0\n");
}*/
