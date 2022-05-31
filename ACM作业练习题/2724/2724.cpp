#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<iostream> 
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct node {
    string name;
    int x, a, b;
    node() {}
    node(string _name, int _x, int _a, int _b)
    {
        name = _name;
        x = _x;
        a = _a;
        b = _b;
    }
    bool operator <(const node& n)const
    {
        return a == n.a ? b > n.b:a > n.a;
    }
};



int main()
{
    string s;
    priority_queue<node> q;
    ios::sync_with_stdio(false);
    int y = 0;
    while (cin >> s)
    {
        if (s[0] == 'G')
        {

            if (q.size())
            {
                node z = q.top();
                q.pop();
                cout << z.name << " " << z.x << endl;
            }
            else
                cout << "EMPTY QUEUE!" << endl;
        }
        else
        {
            y++;
            string na;
            int a, b;
            cin >> na >> a >> b;
            q.push(node(na, a, b, y));
        }
    }
    return 0;
}