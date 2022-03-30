#include <iostream> 
#include "myStack.h"

using namespace std;

int main() {
    stackType<int> stack1;
    stackType<int> stack 2;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);

    stack1.reverseStack(stack2);

    cout<<"Elements in the stack1: ";
    while(!stack1.isEmptyStack()){
      cout<< stack1.top()<<" ";
      stack1.pop();
    }

    cout<<"\n\nElements in the stack2: ";
    while(!stack2.isEmptyStack()){
      cout<<stack2.top()<<" ";
      stack2.pop();
    }
    return 0;
}
