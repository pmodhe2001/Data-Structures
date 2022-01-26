#include <iostream>

using namespace std;

int main()
{
   int a=3;int b=7;
   
   cout<<(a & b)<<endl; // Why cout<<a & b<<endl; does n't works ?
   /*  3=011
       7=111
        =&&&
       3=011
   */
   
   cout<<(a | b)<<endl;
   /*
      3=011
      7=111
       =|||
      7=111
    */
    
    cout<<(a ^ b)<<endl;
   /*
      3=011
      7=111
       =^^^
      4=100
   */
   
   cout<<(~a)<<endl; 
   cout<<(~b)<<endl;
   /*
    Why result is in -ve ?
   */
   
   cout<<(a<<2)<<endl; // Left Shift
   /*
   original : 00011 => 3
   after 2 left shift : 01100 => 12
   */
   
   cout<<(a>>2)<<endl; // Right shift
   /*
   original : 00011 => 3
   after 2 right shift : 000 => 0
   */
   
}
