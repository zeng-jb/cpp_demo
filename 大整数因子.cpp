#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[31];
	int i,k;
	gets(a);
	#include <cstdio>

//��λ����ߣ���λ���ұ�
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
��������������������������������
��Ȩ����������ΪCSDN������serene94����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_32779119/article/details/79513480
}
