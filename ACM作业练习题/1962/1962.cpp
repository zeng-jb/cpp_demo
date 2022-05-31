#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 550;
const int MAXNLEN = 130;
int F[MAXN][MAXNLEN];
char Fi[MAXN][MAXNLEN], ans[MAXN];

void Fibo()
{
    F[1][0] = 1;
    F[2][0] = 2;
    for (int i = 3; i <= 500; ++i)
    {
        for (int j = 0; j <= 110; ++j)
        {
            F[i][j] = F[i][j] + F[i - 1][j] + F[i - 2][j];
            if (F[i][j] >= 10)
            {
                F[i][j + 1] += F[i][j] / 10;
                F[i][j] %= 10;
            }
        }
    }
    for (int i = 1; i <= 500; ++i)
    {
        int j;
        for (j = 110; j >= 0; j--)
            if (F[i][j] == 0)
                continue;
            else
                break;
        int k = 0;
        for (; j >= 0; j--)
            Fi[i][k++] = F[i][j] + '0';
        F[i][k] = '\0';
    }
    //    for(int i = 1; i <= 50; ++i)
    //    {
    //        for(int j = 0; j < strlen(Fi[i]); j++)
    //            printf("%c",Fi[i][j]);
    //        printf("\n");
    //    }
}

int cmp(char* A, char* B)
{
    int LenA = strlen(A);
    int LenB = strlen(B);
    if (LenA != LenB)
        return LenA > LenB ? 1 : -1;
    else
        return strcmp(A, B);
}

int Search(char* Num, bool& flag)
{
    int low = 1;
    int high = 480;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int res = cmp(Num, Fi[mid]);
        if (res == 0)
        {
            flag = 1;
            return mid;
        }
        else if (res < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
char A[MAXNLEN], B[MAXNLEN];

int main()
{
    Fibo();
    while (cin>>A>>B)
    {
        if (strcmp(A, "0") == 0 && strcmp(B, "0") == 0)
            break;

        bool FlagA = 0;
        bool FlagB = 0;
        int Left = Search(A, FlagA);
        int Right = Search(B, FlagB);

        if (FlagB)
            printf("%d\n", Right - Left + 1);
        else
            printf("%d\n", Right - Left);
    }
    return 0;
}