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
        //�ҵ���Լ��
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
    *num1=(*den2)*(*num1)+(den1_t)*(*num2);//������den1��ֵ�Ѿ��ı�
}
void simply(long *num1,long *den1)
{
    long i;
    for(i=2;i<*num1;i++)
    {
        //�ҵ���Լ��
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
    for(i=0;i<N-1;i++) //����ʣ���N-1��ֵ
    {
        scanf("%ld/%ld",&num2,&den2);
        add(&num1,&den1,&num2,&den2);
        if(num1<0)
        {
            flag=1;
            num1=-(num1);//�������Ӿ�Ϊ��ֵ���ڻ����ʱ��Ϳ�������ʹ�ú���
        }
       simply(&num1,&den1);
       if(flag)
       {
           num1=-num1;
           flag=0;
       }
    }
    //�Խ�����д�����
    a=num1/den1;
    if(num1<0)
    {
        num1=-num1;
        flag=1;
    }
    num1=num1%den1;
    simply(&num1,&den1);//ȷ��������ȫ
    //��ԭ
    if(flag)
    {
        num1=-num1;
    }
    if(a)//������������
    {  if(num1==0) printf("%d",a);//���ֻ����������
       else printf("%d ",a);//ע�����ϸ���ƿո�
    }
    if(num1!=0)
    {
        printf("%d/%d",num1,den1);
    }
    if(num1==0&&a==0) printf("0\n");
}*/
