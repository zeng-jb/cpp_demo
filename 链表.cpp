#include <iostream>
#include"class.h"

using namespace std;

void main()
{


	List<char> list;
	Node<char>* a1, * b1, * c1;
	int a, b, c;

	list.Createlist();
	list.Sort(a, b, c);
	list.Circlink(a1, b1, c1, a, b, c);

	cout << "Êý×Ö×Ö·ûÔªËØ£º" << endl;
	list.Output(a1);
	cout << "Ó¢ÎÄ×ÖÄ¸ÔªËØ£º" << endl;
	list.Output(b1);
	cout << "ÆäËû×Ö·ûÔªËØ£º" << endl;
	list.Output(c1);

}
