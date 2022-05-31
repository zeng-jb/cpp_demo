#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 500;
int fib[2000][maxn];
void Fibs()
{
    memset(fib, 0, sizeof(fib));
    fib[1][0] = 1;
    fib[2][0] = 2;
    for (int i = 3; i < 1500; i++)
    {
        int ans = 0;
        for (int j = 0; j < maxn; j++)
        {
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j] + ans;
            ans = fib[i][j] / 10;
            fib[i][j] %= 10;
        }
    }
}
int main()
{
    char str_1[maxn], str_2[maxn];
    int num_1[maxn], num_2[maxn], length_1, length_2;
    Fibs();
    while (cin>>str_1>>str_2 )
    {
        int begin, end, len_1, len_2;
        if (str_1[0] == '0' && str_2[0] == '0')
            break;
        length_1 = strlen(str_1);
        length_2 = strlen(str_2);
        for (int i = 0; i < length_1; i++)
            num_1[i] = str_1[length_1 - i - 1] - '0';
        for (int i = 0; i < length_2; i++)
            num_2[i] = str_2[length_2 - i - 1] - '0';
        for (int i = 1; i < 1500; i++)
        {
            bool isFind = false;
            for (int j = maxn - 1; j >= 0; j--)
            {
                if (fib[i][j])
                {
                    len_1 = j + 1;
                    break;
                }
            }
            if (len_1 < length_1)
                continue;
            if (len_1 > length_1)
            {
                begin = i;
                break;
            }
            for (int j = len_1 - 1; j >= 0; j--)
            {
                if (j == 0 && fib[i][j] == num_1[j])
                    isFind = true;
                if (fib[i][j] == num_1[j])
                    continue;
                if (fib[i][j] > num_1[j])
                    isFind = true;
                break;
            }
            if (isFind)
            {
                begin = i;
                break;
            }
        }
        for (int i = 1499; i > 0; i--)
        {
            bool isFind = false;
            for (int j = maxn - 1; j >= 0; j--)
            {
                if (fib[i][j])
                {
                    len_2 = j + 1;
                    break;
                }
            }
            if (len_2 > length_2)
                continue;
            if (len_2 < length_2)
            {
                end = i;
                break;
            }
            for (int j = len_2 - 1; j >= 0; j--)
            {
                if (j == 0 && fib[i][j] == num_2[j])
                    isFind = true;
                if (fib[i][j] == num_2[j])
                    continue;
                if (fib[i][j] < num_2[j])
                    isFind = true;
                break;
            }
            if (isFind)
            {
                end = i;
                break;
            }
        }
        printf("%d\n", end - begin + 1);
    }
    return 0;
}