#include<iostream>
using namespace std;

template<class var>
class nodeType
{
    template<class U> friend class myLinkedList;
    private:
        T data;
        nodeType<T> *next;
    public:
        nodeType();
};

template<class T>
nodeType<T>::nodeType(){
    this->next=NULL:
}

template<class T>


int main(){

    cout<<"My name is Mary Angeline Samson";
    
    return 0;
}