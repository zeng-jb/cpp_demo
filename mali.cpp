#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#include <IOSTREAM>
string s[31];
int main()
{
	for(int i=1;i<=22;i++)
		getline(cin,s[i]);
	system("cls");
	for(int i=1;i<=22;i++)
		cout<<"printf(\""<<s[i]<<"\\n\");\n";
	for(;;);
	return 0;
}