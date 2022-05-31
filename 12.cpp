#include <stdio.h>
int main()
{
    int n,f1,f2,i;
    f1=f2=1;
    scanf("%d",&n);
    if(n==1) {printf("%d",f1); return 0;}
    for(i=2;;){
        f1=f1+f2;
        i++;
           if(f1>=n) break;
        f2=f2+f1;
        i++;
            if(f1<n&&f2>=n) break ;
    }
    printf("%d",i);
    return 0;
}
