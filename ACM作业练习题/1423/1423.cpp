#include <iostream>
#include <stdio.h>

using namespace std;

char s[300], d[300];

void func(int i)  //È¥µô')'
{
    int cnt = 0;
    for (i++; s[i] != '\0'; i++)
    {
        if (s[i] == '(') cnt++;
        else if (s[i] == ')')
        {
            if (!cnt)
            {
                s[i] = ' ';
                return;
            }
            cnt--;
        }
    }
}

int main()
{
    int n, i, j;
   // scanf("%d", &n);
    cin >> n;
    getchar();
    while (n--)
    {
        gets_s(s);
        for (i = 0, j = -1; s[i] != '\0'; i++)
        {
            if (s[i] == ' ') continue;
            else if (s[i] == '(')
            {
                if (j == -1 || d[j] == '+' || d[j] == '(') func(i);
                else if (d[j] == '-')
                {
                    int k, cnt = 0, tag = 0;
                    for (k = i + 1; s[k] != '\0'; k++)
                    {
                        if (s[k] == '(') cnt++;
                        else if (s[k] == ')')
                        {
                            if (!cnt) break;
                            cnt--;
                        }
                        else if (s[k] == '+' || s[k] == '-')
                        {
                            if (!cnt)
                            {
                                tag = 1;
                                break;
                            }
                        }
                    }
                    if (tag) d[++j] = s[i];
                    else func(i);
                }
            }
            else d[++j] = s[i];
        }
        d[++j] = '\0';
        printf("%s\n", d);
    }
    return 0;
}