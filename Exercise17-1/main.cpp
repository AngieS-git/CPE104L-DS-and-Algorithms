#include <iostream>
#include "myStack.h"

using namespace std;

int main() {
      cout << "\n\n\tProgram to overload the realtional "
   << "operator == for the class stackType.";

  stackType<int> s1( 12 );
  stackType<int> s2( 15 );

  cout << "\n\n\tInserting elements 5, 10, 15 ... "
   << "to both the stacks.";
  for ( int i = 5; i < 50; i+=5 )
  {
   s1.push( i );
   s2.push( i );
  }

  if ( s1 == s2 ){
    cout << "\n\tBoth the stacks are equal";
  }
  else{
     cout << "\n\tBoth the stacks are not equal";
  }
  
  cout<<"\n\tInserting element 11 to the second stack.";
  s2.push( 11 );

  if ( s1 == s2 )
   cout << "\n\tBoth the stacks are equal";
  else
   cout << "\n\tBoth the stacks are not equal";
   
  cout << "\n\n\t";
  system("pause");
  
    return 0;
}
