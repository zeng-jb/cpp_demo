#include <stdio.h>
int main()
{
	int time,i,j=0;
	int t=0,w=0;
	scanf("%d",&time);
	for(i=0;i<=time;){
		w=3*i;
		t=9*(i-j*30);
		if(i%10==0&&t>w&&i!=0){
			i+=30;
			if(i>time){
				w=3*time;
				break;
			}
			j++;
		}else{
			i++;
		}
	}
	if(t>w) printf("^_^ %d\n",t);
	else if(t<w) printf("@_@ %d\n",w);
	else printf("-_- %d\n",w);
	return 0;
}

