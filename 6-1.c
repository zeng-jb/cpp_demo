
#include <stdio.h>
int gys(int m,int n);
int main()
{
int n=0;
int m=0;
int gc=0;
scanf("%d%d",&n,&m);
gc=gys(m,n);
printf("%d\n",gc);

return 0;
}
int gys(int m,int n)
{
	int r =0;
r=m%n;
if(r<0)
return 0;
else if (r==0)
return n;
else if (r>0)
return gys(n,r);
}

