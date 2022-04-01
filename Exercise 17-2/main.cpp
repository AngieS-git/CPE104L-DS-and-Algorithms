
#include<iostream>
#include "linkedStack.h"

using namespace std;

int main() {
      cout << "\n\n\tProgram to overload the realtional "
   << "operator == for the class stackType.";

  linkedStackType<int> stack1;
  linkedStackType<int> stack2;

  cout << "\n\n\tInserting elements 5, 10, 15 ... "
   << "to both the stacks.";
  for ( int i = 5; i < 50; i+=5 )
  {
   stack1.push( i );
  }

  if ( stack1 == stack2 )
   cout << "\n\tBoth the stacks are equal";
  else
   cout << "\n\tBoth the stacks are not equal";

  cout<<"\n\tInserting element 11 to the second stack.";
  stack1.push( 90 );

  if ( stack1 == stack2 )
   cout << "\n\tBoth the stacks are equal";
  else

  while(!stack1.isEmptyStack())
  {
    cout<<stack1.top()<<" ";
    stack1.pop();
  }
  while(!stack2.isEmptyStack())
  {
    cout<<stack2.top()<<" ";
    stack2.pop();

  }
   cout << "\n\tBoth the stacks are not equal";
  cout << "\n\n\t";
  system("pause");
  
    return 0;
}
