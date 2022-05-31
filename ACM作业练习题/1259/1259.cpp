//使用两个栈和一个队列
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(void)
{
    int n, temp;
    while (cin >> n && n)
    {
        while (cin >> temp && temp)
        {
            stack<int>order, save; //save是一个暂存栈，象征着车站station
            queue<int>check;  //check为待检查的（是否合法的、可能的出栈）序列
            for (int i = n; i >= 1; i--)
            {
                order.push(i);
                check.push(temp);
                if (i != 1) cin >> temp;
            }
            //save和push底部都先放置了哨兵值0,以便以后易于判断
            save.push(0);
            check.push(0);
            while (1)
            {
                if (check.front() == save.top())
                {
                    check.pop();
                    save.pop();
                }
                else if (check.front() == order.top())
                {
                    check.pop();
                    order.pop();
                }
                else
                {
                    save.push(order.top());
                    order.pop();
                }
                if (order.empty() && save.top() && check.front() != save.top()) //关键
                {
                    cout << "No" << endl;
                    break;
                }
                if (check.front() == 0) //check序列为“空（到底了）”
                {
                    cout << "Yes" << endl;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}