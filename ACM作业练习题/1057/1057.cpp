#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 999999999
using namespace std;
int a[100], b[100];
int main()
{
    //freopen("2.txt","w",stdout);
    int n, count = 0;
    while (cin >> n && n)
    {
        if (count) cout << endl;/*Êä³ö¿ÕÐÐ*/
        count++;
        int i, j, scorea = 0, scoreb = 0;
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] + b[i] == 3)
            {
                if (a[i] > b[i]) scoreb += 6;
                else scorea += 6;
            }
            else if (abs(a[i] - b[i]) == 1)
            {
                if (a[i] > b[i]) scoreb += (a[i] + b[i]);
                else
                    scorea += (a[i] + b[i]);
            }
            else if (a[i] == b[i]) continue;
            else
            {
                //if(i == 0) cout<<a[i]<<"********"<<b[i]<<endl;
                if (a[i] > b[i]) scorea += a[i];//,cout<<a[i]<<"**"<<scorea + a[i]<<endl;
                else
                    scoreb += b[i];
            }
        }

        cout << "A has " << scorea << " points." << " B has " << scoreb << " points." << endl;
        //cout<<endl;
    }
    return 0;
}