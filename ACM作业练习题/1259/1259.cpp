//ʹ������ջ��һ������
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
            stack<int>order, save; //save��һ���ݴ�ջ�������ų�վstation
            queue<int>check;  //checkΪ�����ģ��Ƿ�Ϸ��ġ����ܵĳ�ջ������
            for (int i = n; i >= 1; i--)
            {
                order.push(i);
                check.push(temp);
                if (i != 1) cin >> temp;
            }
            //save��push�ײ����ȷ������ڱ�ֵ0,�Ա��Ժ������ж�
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
                if (order.empty() && save.top() && check.front() != save.top()) //�ؼ�
                {
                    cout << "No" << endl;
                    break;
                }
                if (check.front() == 0) //check����Ϊ���գ������ˣ���
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