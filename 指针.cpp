// ��1  ���������ֵ
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
// ���ؽϴ�ֵ������ָ��
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
  //��2 ������Ϊ��������
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


//��   ��ͬ��ʽ���ú���
/*#include<iostream>
using namespace std;
void simple()    // ����һ���򵥺���
{ cout << "It is a simple program.\n" ; }
int main()
{ cout << "Address of function :\n" ;
   cout << simple << endl ;    // �������ǵ�ַ
   cout << & simple << endl ;  // ȡ������ַ
   cout << "Call function ...\n" ;
    simple() ;  // ����ʽ����
   ( & simple )() ;  // ��ַ��ʽ����
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


//������ָ�뷽ʽ���ʶ�ά����
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

//��ָ����Ϊ�����Ĳ���
#include  <iostream>
using namespace std;
int main( )
{ void swap(int *p1,int *p2);     //��������
int *pointer_1,*pointer_2,a,b;  //����ָ�����pointer_1,pointer_2�����ͱ���a,b
cin>>a>>b;
pointer_1=&a;                       //ʹpointer_1ָ��a
pointer_2=&b;                       //ʹpointer_2ָ��b
if(a<b) swap(pointer_1,pointer_2);  //���a<b��ʹ*pointer_1��*pointer_2����
cout<<"max="<<a<<" min="<<b<<endl;//a���Ǵ�����b��С��
return 0;
}
void swap(int *p1,int *p2)            //�����������ǽ�*p1��ֵ��*p2��ֵ����
{ int temp;
temp=*p1;         
*p1=*p2;
*p2=temp;           
}
