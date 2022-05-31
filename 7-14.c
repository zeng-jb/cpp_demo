#include <stdio.h>
int main()
{
	int h,m,m1,m2;
	scanf("%d %d",&m1,&m2);
	h=m1/100;
	m=m1%100;
	
		h+=m2/60;

		if(m2>=0){
			m+=m2%60;
			if(m>=60){
				m=m%60;
				h++;
			}
		}
		else{
			m=m2%60+60;
			h--;
			if(m>=60){
				m=m%60;
				h++;
			}
		}
	
	printf("%d%02d\n",h,m);
	return 0;
}
