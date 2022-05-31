#include<fstream>
#include <iostream>
using namespace std;
int main()
{

    int a = 1127;
    double b = 3.1415;
    ofstream ofs("G:\cpp\\test.txt",ios::binary);
    ofs.write((char*)&a,sizeof(int));
    ofs.write((char*)&b,sizeof(double)); 
    ofs.close();   
    int a1;
    double b1;
    ifstream ifs("G:\cpp\\test.txt",ios::binary);
    ifs.read((char*)&a1,sizeof(int));
    cout<<a1<<endl;
    ifs.read((char*)&b1,sizeof(double));
    cout<<b1<<endl;
    ifs.close();
    return 0;

} 
