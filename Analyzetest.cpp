#include <iostream>
#include "AnalyzeProgram.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"¶ÁÈ¡textÎÄ¼þ"<<endl;
	AnalyzeProgram ana;
	ana.analyse();
	cout<<ana.getResult()<<endl;
	return 0;
}
