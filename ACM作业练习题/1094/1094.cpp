#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<stack>
using namespace std;
const int maxn = 10100;
map<char, pair<int, int> > m;
stack<pair<int, int> >st;
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            char x;
            pair<int, int> p;
            cin >> x;
            scanf("%d%d", &p.first, &p.second);
            m[x] = p;
        }

        char s[1100];
        while (cin >> s)
        {
            int ans = 0, len = strlen(s);
            int ok = 1;
            if (len == 1)
            {
                printf("0\n");//当只有单个矩阵；
                continue;
            }

            for (int i = 0; i < len; i++)
            {
                if (s[i] == '(')
                    continue;

                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    pair<int, int> p = m[s[i]];
                    st.push(p);
                }

                if (s[i] == ')' && st.size() >= 2)
                {
                    pair<int, int> a, b, c;
                    a = st.top(); st.pop();
                    if (st.empty())//矩阵运算结束；
                        break;
                    b = st.top(); st.pop();
                    if (b.second != a.first)
                        //注意a是后面那个矩阵，b才是前面的矩阵，（栈的后进先出）
                    {
                        printf("error\n");
                        ok = 0;
                        break;
                    }

                    ans += b.first * b.second * a.second;
                    c.first = b.first;
                    c.second = a.second;
                    //同样因为栈的特性；
                    st.push(c);
                }
            }
            if (ok)
                printf("%d\n", ans);
        }

    }
    return 0;
}