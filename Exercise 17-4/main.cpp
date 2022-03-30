#include <iostream>
#include "linkedStack.h"

using namespace std;

int main() {
    stackType<int> stack1( 12 );
    stackType<int> stack2( 15 );
    cout << "\n Inserting elements 5, 10, 15 ... to both the stacks.";
    for ( int i = 5; i < 50; i+=5 )
    stack1.push( i );
    stack1.reverseStack( stack2 );
    cout <<"\nThe elements in the !rst stack are:\n\t";
    while( !stack1.isEmptyStack() )
    {
    cout << stack1.top() << " ";
    stack1.pop();
    }
    cout<<"\n\tThe elements in the second stack are:\n\t";
    while( !stack2.isEmptyStack() )
    {
    cout << stack2.top() << " ";
    stack2.pop();
    }
    system("pause");

    return 0;
}