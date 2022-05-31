#include <stdio.h>
int main()
{
    int n,i;
    float h,w,bw,f;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%f%f",&h,&w);
        bw=(h-100)*0.9*2.0;
        f=(w-bw);
        if(f<bw*0.1&&f>bw*0.1*-1) printf("You are wan mei!\n");
        else if(f>bw*0.1) printf("You are tai pand le!\n");
        else printf("You are tai shou le!\n");
    }
    return 0;
}
