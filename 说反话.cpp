#include <iostream>
#include <string.h>
#include<stack>
using namespace std;
int main() {

	stack<string> s;
	string str;
	while(cin >> str)
		s.push(str);
	while (!s.empty()) {
		cout << s.top();
		s.pop();
		if (!s.empty())cout << " ";
	}

}
