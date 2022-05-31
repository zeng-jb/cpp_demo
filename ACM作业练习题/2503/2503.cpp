#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, string> rule;
int main(void)
{
    int cur, len;
    string s, s1, s2;
    while (getline(cin, s))
    {
        if ((cur = s.find(' ')) != string::npos)
        {
            len = s.length();
            s1 = s.substr(0, cur);
            s2 = s.substr(cur + 1, len);
            rule[s2] = s1;
        }
        else
        {
            if (s == "")
                continue;
            if (rule[s] != "")
                cout << rule[s] << endl;
            else
                cout << "eh\n";
        }
    }
    return 0;
}