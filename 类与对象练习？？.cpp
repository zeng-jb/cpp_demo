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

   sample(int val);  //①

   ~sample( );           //②

 private:

  int a=2.5;            //③

 public:

  sample( );            //④

};*/

 /*class AA{

  int a;

 public:

  int getRef( ) const{return &a;}    //①   

  int getValue( ) const{return a;}   //②

  void set(int n) const{a=n;}      //③

  friend void show(AA aa) const{cout<<a;}   //④

};*/
/*	class Test{

public:

  //Test( ){a=0;c=0;}  //①

  //int f(int a) const{this->a=a;}  //②

  void h(int b) {this->b=b;}; //③

  //static int g( ) {return a;}  //④

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

      Name names[3] = {Name("张三") , Name("李四") };

     //数组长度为3，但是只有两个元素

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
