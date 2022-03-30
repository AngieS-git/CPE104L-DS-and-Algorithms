//Header file: myStack.h

#ifndef H_StackType 
#define H_StackType 
 
#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;
  
template <class Type>
class stackType
{


public:
    void initializeStack();
    bool isEmptyStack() const;  
    bool isFullStack() const;
    void push(const Type& );
    Type top() const;
    void pop();
    stackType(int stackSize = 20); 
    ~stackType(); 

    bool operator==(const stackType<Type>& );

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list;       //pointer to the array that holds the
                      //stack elements
};


template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}//end initializeStack


template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}//end isEmptyStack

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop == maxStackSize);
} //end isFullStack

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //add newItem to the 
                                    //top of the stack
        stackTop++; //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);          //if stack is empty, 
                                    //terminate the program
    return list[stackTop - 1];      //return the element of the
                                    //stack indicated by 
                                    //stackTop - 1
}//end top

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;                 //decrement stackTop 
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
stackType<Type>::stackType(int stackSize) 
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        stackSize = 10;
    }
    else
        maxStackSize = stackSize;   //set the stack size to 
                                    //the value specified by
                                    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
    list = new Type[maxStackSize];  //create the array to
                                    //hold the stack elements
}//end constructor

template <class Type>
stackType<Type>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied 
                    //by the array
}//end destructor

template <class Type>
bool stackType<Type>:: operator==(const stackType<Type>& right)
{
    if(this->stackTop!=right.stackTop)
        return false;
    
    for(int i = 0; i < stackTop; i++  )
    {
        if(this-> list[i] != right.list [i])
            return false;
    }
    return true;
}

#endif
