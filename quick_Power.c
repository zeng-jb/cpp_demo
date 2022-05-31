#include <stdio.h>

int Power(int, int);

const int MOD = 10007;
int main()
{
    int N, k;
    scanf("%d%d", &N, &k);
    printf("%d\n", Power(N, k));        
    return 0;
}

/* Your function will be put here */
int Power(int n,int k){
	int y;
    n%=MOD;
	if(k==0){
		y=1;
	} 
	else{
         y=Power(n,k/2);
         y=(y*y)%MOD;
        if(k%2==1) {y=(n*y)%MOD;}
    }
	return y;
} 

// int Power(int N, int k)
// {
//     N %= MOD;
//     if (k == 0)
//         return 1;
//     if (k > 0) {
//         if (k % 2 == 1)
//         {
//             return N * Power(N, k - 1) % MOD;
//             k /= 2;
//         }
//         else
//         {
//             k /= 2;
//             return Power(N, k)*Power(N, k) % MOD;
//         }
//     }
// }
