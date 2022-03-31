//Header File: linkedStack.h

#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>



using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedStackType
{
public:
    const linkedStackType<Type>& operator=
                              (const linkedStackType<Type>&);

    bool isEmptyStack() const;


    bool isFullStack() const;


    void initializeStack();

    void push(const Type& newItem);

    Type top() const;


    void pop();

    linkedStackType();

    linkedStackType(const linkedStackType<Type>& otherStack);


    ~linkedStackType();

    void reverseStack(linkedStackType<Type> &otherStack);

private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack);

};

    //Default constructor
template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = nullptr;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == nullptr);
} //end isEmptyStack

template <class Type>
bool linkedStackType<Type>:: isFullStack() const
{
    return false;
} //end isFullStack

template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> *temp; //pointer to delete the node

    while (stackTop != nullptr)    //while there are elements in
                                //the stack
    {
        temp = stackTop;    //set temp to point to the
                            //current node
        stackTop = stackTop->link;  //advance stackTop to the
                                    //next node
        delete temp;    //deallocate memory occupied by temp
    }
} //end initializeStack

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;  //pointer to create the new node

    newNode = new nodeType<Type>; //create the node

    newNode->info = newElement; //store newElement in the node
    newNode->link = stackTop; //insert newNode before stackTop
    stackTop = newNode;       //set stackTop to point to the
                              //top node
} //end push


template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr); //if stack is empty,
                              //terminate the program
    return stackTop->info;    //return the top element
}//end top

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;   //pointer to deallocate memory

    if (stackTop != nullptr)
    {
        temp = stackTop;  //set temp to point to the top node

        stackTop = stackTop->link;  //advance stackTop to the
                                    //next node
        delete temp;    //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
void linkedStackType<Type>::copyStack
                     (const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != nullptr) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack
        stackTop = new nodeType<Type>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = nullptr;  //set the link field of the
                                //node to nullptr
        last = stackTop;        //set last to point to the node
        current = current->link;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

    //copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(
                      const linkedStackType<Type>& otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}//end copy constructor

    //destructor
template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}//end destructor

    //overloading the assignment operator
template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=
    			  (const linkedStackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
}//end operator=

template <class Type>
void stackType<Type>::reverseStack (stackType<Type> &otherStack){



otherStack.initializeStack();

 for(int i=stackTop-1;i>=0;i--){

 otherStack.push(list[i]);
 }
}

template<class Type>
void linkedStackType<Type>::reverseStack(linkedStackType<Type> &otherStack)
 // Declare the required variable
 int lp;

 // Destroy the stack2 contents
 otherStack.initializeStack();

 // Check stack2 size is less than the stact1 elements count
 if (stack_Top > otherStack.max_Size)
 {
 cout << "The other stack size is less than the number of
 elements available in the current stack." << endl;
 cout << "so this stack cannot be reversed." << endl;
 }
 else
 {
 // Initialize the stack2 top value
 otherStack.stack_Top = stack_Top;

 for (int i = stackTop -1; i>=0;i--)
 otherStack.push(list[i]);
 }
}

#endif
