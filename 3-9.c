#include <stdio.h>
int main()
{
//	int n;
	  int i,j;

    for (i=0; i<6; i++) {

        for (j=6;j>i ;j-- ) {

            printf("");

        }

        for (j=0; j<=i; j++) {

            printf("*");

        }

        printf("\n");

    }
    return 0;
} 
