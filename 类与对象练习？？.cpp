/*#include <iostream>
#include <string.h>
using namespace std;*/

/*	 class sample {
	
	  int n;
	
	public:
	
	  sample (int i=0):n(i){ }
	
	  void setValue(int n0);
	
	};
	 void sample::setValue(int n0){n=n0;}*/
	 
	 
/*class sample{

 public:

   sample(int val);  //��

   ~sample( );           //��

 private:

  int a=2.5;            //��

 public:

  sample( );            //��

};*/

 /*class AA{

  int a;

 public:

  int getRef( ) const{return &a;}    //��   

  int getValue( ) const{return a;}   //��

  void set(int n) const{a=n;}      //��

  friend void show(AA aa) const{cout<<a;}   //��

};*/
/*	class Test{

public:

  //Test( ){a=0;c=0;}  //��

  //int f(int a) const{this->a=a;}  //��

  void h(int b) {this->b=b;}; //��

  //static int g( ) {return a;}  //��

private:

  int a;

  static int b;

  const int c;

};

int Test::b=0;*/

/*class Name

{

     char name[20];

public:

    Name()

    {

          strcpy(name , "");

          cout<<'?';

    }

    Name(char *fname)

    {

          strcpy(name , fname);

          cout<<'?';

     }

 };

int main( )

{

      Name names[3] = {Name("����") , Name("����") };

     //���鳤��Ϊ3������ֻ������Ԫ��

  }*/
  
  #include <iostream>     

using namespace std;      

class myClass{     

 public: 

         myClass(){++count;}       

       ~myClass(){--count;} 

        static int getcount(){return count;}

 private :

      static int count; 

}; 

int myClass::count=0;

 int main(){ 

    myClass obj; 

    cout<<obj.getcount(); 

   myClass*ptr=new myClass;   

    cout<<myClass::getcount(); 

   delete ptr; 

   cout<<myClass::getcount();   

   return( 0); 

}  
