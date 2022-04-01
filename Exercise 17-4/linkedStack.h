//Header File: linkedStack.h

#ifndef H_LinkedStackType 
#define H_LinkedStackType 

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
                              (const linkedStackType<Type> &);
    bool operator==(const linkedStackType<Type>& );
      //Overload the assignment operator.

    bool isEmptyStack() const;

    bool isFullStack() const;
    void initializeStack();

    void push(const Type& );
    Type top() const;

    void pop();

    linkedStackType(); 
     

    linkedStackType(const linkedStackType<Type> &); 
      //Copy constructo

    ~linkedStackType();

    void reverseStack(linkedStackType<Type> &);

private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& ); 

};

template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> *temp; //pointer to delete the node

    while (stackTop != NULL)    //while there are elements in 
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
bool linkedStackType<Type>:: isFullStack() const
{
    return false;
} //end isFullStack

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == NULL);
} //end isEmptyStack

template <class Type>
void linkedStackType<Type>::push(const Type& newItem)
{
    nodeType<Type> *newNode;  //pointer to create the new node

    newNode = new nodeType<Type>; //create the node

    newNode->info = newItem; //store newElement in the node
    newNode->link = stackTop; //insert newNode before stackTop
    stackTop = newNode;       //set stackTop to point to the 
                              //top node
} //end push

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;   //pointer to deallocate memory

    if (stackTop != NULL)
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
Type linkedStackType<Type>::top() const
{
    assert(stackTop != NULL); //if stack is empty,
                              //terminate the program
    return stackTop->info;    //return the top element 
}//end top

    //Default constructor
template <class Type> 
linkedStackType<Type>::linkedStackType()
{
    stackTop = NULL;
}

    //copy constructor
template <class Type>   
linkedStackType<Type>::linkedStackType(
                      const linkedStackType<Type> &otherStack)
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
void linkedStackType<Type>::copyStack
                     (const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack 
        stackTop = new nodeType<Type>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = NULL;  //set the link field of the
                                //node to nullptr
        last = stackTop;        //set last to point to the node
        current = current->link;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

template <class Type>
bool linkedStackType<Type>::operator==( const linkedStackType<Type> &otherStack)
{
    if((this->stackTop==NULL)&&(otherStack.stackTop==NULL))
    {
        return true;
    }

    nodeType<Type> *temp1, *temp2;

    temp1= this->stackTop;
    temp2= otherStack.stackTop;

    while((temp1!=NULL)&&(temp2!=NULL)){
        if(temp1->info!=temp2->info){
            return false;
        }
        else{
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
    }

    if((temp1!=NULL)||(temp2!=NULL))
    {
        return false;
    }
    return true;
}

template <class Type>
void linkedStackType<Type>::reverseStack(linkedStackType<Type>& right)
{
 right.initializeStack();
 nodeType<Type> *temp = this->stackTop;

 while(temp!=NULL)
 {
     right.push(temp->info);
     temp = temp->link;
 }
}

#endif
