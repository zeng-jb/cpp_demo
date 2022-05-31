#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[31];
	int i,k;
	gets(a);
	#include <cstdio>

//高位在左边，低位在右边
int BigNumMod(int BigNum[], int c, int length){
    int ans = 0;
    for(int i = 0; i < length; i++)
        ans = ((ans * 10) + BigNum[i]) % c;
    return ans;
}

int main()
{
    int BigNum[7] = {1,2,3,4,5,6,7};
    int c = 3;
    printf("%d\n", BigNumMod(BigNum, c, 7));
    return 0;
}
————————————————
版权声明：本文为CSDN博主「serene94」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_32779119/article/details/79513480
}
