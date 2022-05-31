// 例1  交换对象的值
/*# include <iostream>
using namespace std; 
void  swap ( int & ,   int &  ) ;
int  main ()
{  int  a = 3 ,   b = 8 ;
   cout << "a = " << a << ", b = " << b << endl ;
   swap (a , b ) ;
   cout <<"after swapping... \n" ;
   cout << "a = " << a << ", b = " << b << endl ;
   
   return 0;
}
void  swap ( int  & x ,  int  & y )
{  int  temp = x ;
    x  = y  ;
   y =  temp ;}
*/
// 返回较大值变量的指针
/*#include<iostream>
using namespace std;
int * maxPoint(int * x, int * y ) ;
int  main()
{ int a, b ;
  cout << "Input a, b : " ;
  cin >> a >> b ;
  cout << * maxPoint( &a, &b ) <<endl ;
}
int * maxPoint(int * x, int * y )
{ if ( *x > *y )  return x ;
  return y ; }*/
  //例2 引用作为函数函数
/*#include<iostream>
#include<iomanip>
using namespace std;
void display( const int & rk )
{ cout << dec << rk << " :\n"
             << "dec : " << rk << endl
             << "oct : " << oct << rk << endl
             << "hex : " << hex << rk << endl;
}
int  main()
{
      display( 4589 ) ;
      display(16);
      return 0;
}*/


//例   不同方式调用函数
/*#include<iostream>
using namespace std;
void simple()    // 定义一个简单函数
{ cout << "It is a simple program.\n" ; }
int main()
{ cout << "Address of function :\n" ;
   cout << simple << endl ;    // 函数名是地址
   cout << & simple << endl ;  // 取函数地址
   cout << "Call function ...\n" ;
    simple() ;  // 名方式调用
   ( & simple )() ;  // 地址方式调用
}*/

/*#include<iostream>
using namespace std;

int  main()
{ int a = 11 ,  b = 22 ,  c = 33 , * pi [ 3 ] ;
   pi [ 0 ] = &a ;
   pi [ 1 ] = &b ;
   pi [ 2 ] = &c ;
   for( int i = 0; i < 3 ;  i ++ )
        cout << *pi [ i ] <<  "  ";
}
*/


//例：用指针方式访问二维数组
/*#include<iostream>
using namespace std;
int main()
{
  double b[2][3] = {1.1,2.2,3.3,4.4,6.5,6.6};
  double (*p_array)[3];
  p_array=b;
  for (int i=0;i<2;i++) {
  for (int j=0;j<3;j++) {
  cout<<*(*(p_array+i)+j)<<"\t";
  }
  cout<<endl;
  }
}*/

//例指针作为函数的参数
#include  <iostream>
using namespace std;
int main( )
{ void swap(int *p1,int *p2);     //函数声明
int *pointer_1,*pointer_2,a,b;  //定义指针变量pointer_1,pointer_2，整型变量a,b
cin>>a>>b;
pointer_1=&a;                       //使pointer_1指向a
pointer_2=&b;                       //使pointer_2指向b
if(a<b) swap(pointer_1,pointer_2);  //如果a<b，使*pointer_1和*pointer_2互换
cout<<"max="<<a<<" min="<<b<<endl;//a已是大数，b是小数
return 0;
}
void swap(int *p1,int *p2)            //函数的作用是将*p1的值与*p2的值交换
{ int temp;
temp=*p1;         
*p1=*p2;
*p2=temp;           
}
