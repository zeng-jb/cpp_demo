/*#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[101];
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len-1;i++){
		cout<<char((int)(s[i]+s[i+1]));
	}
	cout<<char((int)(s[len-1]+s[0]));
	
 } */
 #include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int i;
    string s;
    getline(cin, s);
    char ch = s[0];
    for (i=0; i<s.size()-1; i++){
        s[i] += s[i+1];
    }
    s[i] += ch;
    cout << s << endl;
    return 0;
}
