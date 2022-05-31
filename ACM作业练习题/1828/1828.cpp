#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int fb[6001][1003];
int main()
{
    int len[6002];
    int n, i, j;
    memset(fb, 0, sizeof(fb));
    fb[1][0] = fb[2][0] = 1;
    len[1] = len[2] = 1;
    for (i = 3; i <= 6000; i++)
    {
        memcpy(fb[i], fb[i - 1], sizeof(fb[i - 1])); //直接把第一项的值赋值到当前所求项上 
        for (j = 0; j < len[i - 2]; j++)//与以往的大数加法有少许不同
        {
            fb[i][j] += fb[i - 2][j];
        }
        for (j = 0; j < max(len[i - 1], len[i - 2]); j++)
        {
            if (fb[i][j] > 9)fb[i][j + 1] += fb[i][j] / 10;
            fb[i][j] %= 10;
        }
        if (fb[i][j] != 0)
        {
            j++;
        }
        len[i] = j;
    }
    while (cin >> n)
    {
        for (int k = len[n] - 1; k >= 0; k--)
        {
            cout << fb[n][k];
        }
        cout << endl;
    }
    return 0;
}