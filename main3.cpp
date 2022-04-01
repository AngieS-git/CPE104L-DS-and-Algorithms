#include<iostream>

using namespace std;

template<typename T>
class Stack
{
    private:
        T *stackArray;
        int top;
        int size;

    public:
        Stack(int);
        ~Stack();
        int getSize();
        void pushIt(T);
        void popIt(T);
        void printStack();
        bool isEmpty();
        bool isFull();
        void updateStack();
};

template<typename T>
bool Stack<T>::isEmpty()
{
    return (top==-1);
}

template<typename T>
bool Stack<T>::isFull()
{
    return (top==size-1);
}

template<typename T>
int Stack<T>::getSize()
{
    return (top+1);
}

template<typename T>
void Stack<T>::updateStack()
{
    this->size=getSize()-1;

    T *temp=new T[size];

    for(int i=0;i<size;i++)
        temp[i]=stackArray[i];

    delete[] stackArray;

    stackArray=new T[size];

    for(int i=0;i<size;i++)
        stackArray[i]=temp[i];

    delete[] temp;
}

template<typename T>
Stack<T>::Stack(int size)
{
    this->stackArray=new T[size];
    this->size=size;
    this->top=-1;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] stackArray;
}

template<typename T>
void Stack<T>::pushIt(T item)
{
    if(!isFull())
    {
        cout<<"Pushing "<<item<<"!"<<endl;
        stackArray[top++]=item;
    }
    else
    {
        cout<<"Stack is full!"<<endl;
    }
}

template<typename T>
void Stack<T>::popIt(T item)
{
    if(!isEmpty())
    {
        cout<<"Popping "<<item<<" ";
        stackArray[top--] = item;
        //stackArray[top--];
        updateStack();
        top--;
    }
    else
    {
        cout<<"Stack is empty!"<<endl;
    }
}

template<typename T>
void Stack<T>::printStack()
{
    if(!isEmpty())
    {
        cout<<"Stack contents: ";

        for(int i=0;i<size;i++)
        {
            cout<<stackArray[i]<<" | ";
        }

        cout<<endl;
    }
    else
    {
        cout<<"Stack is empty!"<<endl;
    }
}

int main()
{
    int size, ctr=0, option;
    double item;
    char quitFlag;

    cout<<"Specify the size of the stack: ";
    cin>>size;

    Stack<double> myStack(size);

    do
    {
        cout<<"\nMenu"<<endl
            <<"[1] Push an item."<<endl
            <<"[2] Pop an item."<<endl
            <<"[3] Print stack."<<endl
            <<"[4] Exit."<<endl
            <<"Option: ";
            cin>>option;

        switch(option)
        {
            case 1:
                do
                {
                    cout<<"Enter an item to push: ";
                    cin>>item;

                    myStack.pushIt(item);

                    ctr++;

                }while(ctr<myStack.getSize());

                break;
            case 2:
                myStack.popIt(item);
                break;
            case 3:
                myStack.printStack();
                break;
            case 4:
                cin>>quitFlag;
                break;
            default:
                cout<<"Invalid selection! Try again!"<<endl;
        }
    }while(quitFlag!='Y' || quitFlag!='y');

    return 0;
}
