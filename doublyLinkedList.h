//doublyLinkedList.h
#ifndef H_doublyLinkedList
#define H_doublyLinkedList
#include <iostream>
#include <cassert>
using namespace std;
//De!nition of the node
template <class Type>
struct nodeType
{
 Type info;
 nodeType<Type> *next;
 nodeType<Type> *back;
};
template <class Type>
class doublyLinkedList
{
public:
 const doublyLinkedList<Type>& operator=
 (const doublyLinkedList<Type> &);
 //Overload the assignment operator.
 void initializeList();
 //Function to initialize the list to an empty state.
 bool isEmptyList() const;
 //Function to determine whether the list is empty.
 void destroy();
 //Function to delete all the nodes from the list.
 void print() const;
 //Function to output the info contained in each node.
 void reversePrint() const;
 //Function to output the info contained in each node
 //in reverse order.
 int length() const;
 //Function to return the number of nodes in the list.
 Type front() const;
 //Function to return the !rst element of the list.
 Type back() const;
 //Function to return the last element of the list.
 bool search(const Type& searchItem) const;
 //Function to determine whether searchItem is in the list.
 void insert(const Type& insertItem);
 //Function to insert insertItem in the list.
 void deleteNode(const Type& deleteItem);
 //Function to delete deleteItem from the list.
 doublyLinkedList();
 //default constructor
 doublyLinkedList(const doublyLinkedList<Type>& otherList);
 //copy constructor
 ~doublyLinkedList();
 //destructor
protected:
 int count;
 nodeType<Type> *!rst; //pointer to the !rst node
 nodeType<Type> *last; //pointer to the last node
private:
 void copyList(const doublyLinkedList<Type>& otherList);
 //Function to make a copy of otherList.
};
template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
 !rst= NULL;
 last = NULL;
 count = 0;
}
template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
 return (!rst == NULL);
}
template <class Type>
void doublyLinkedList<Type>::destroy()
{
 nodeType<Type> *temp; //pointer to delete the node
 while (!rst != NULL)
 {
 temp = !rst;
 !rst = !rst->next;
 delete temp;
 }
 last = NULL;
 count = 0;
}
template <class Type>
void doublyLinkedList<Type>::initializeList()
{
 destroy();
}
template <class Type>
int doublyLinkedList<Type>::length() const
{
 return count;
}
template <class Type>
void doublyLinkedList<Type>::print() const
{
 nodeType<Type> *current; //pointer to traverse the list
 current = !rst; //set current to point to the !rst node
 while (current != NULL)
 {
 cout << current->info << " "; //output info
 current = current->next;
 }//end while
}//end print
template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
 nodeType<Type> *current; //pointer to traverse
 //the list
 current = last; //set current to point to the
 //last node
 while (current != NULL)
 {
 cout << current->info << " ";
 current = current->back;
 }//end while
}//end reversePrint
template <class Type>
bool doublyLinkedList<Type>::
search(const Type& searchItem) const
{
 bool found = false;
 nodeType<Type> *current; //pointer to traverse the list
 current = !rst;
 while (current != NULL && !found)
 if (current->info >= searchItem)
 found = true;
 else
 current = current->next;
 if (found)
 found = (current->info == searchItem); //test for
 //equality
 return found;
}//end search
template <class Type>
Type doublyLinkedList<Type>::front() const
{
 assert(!rst != NULL);
 return !rst->info;
}
template <class Type>
Type doublyLinkedList<Type>::back() const
{
 assert(last != NULL);
 return last->info;
}
template <class Type>
void doublyLinkedList<Type>::insert(const Type& insertItem)
{
 nodeType<Type> *current; //pointer to traverse the list
 nodeType<Type> *trailCurrent; //pointer just before current
 nodeType<Type> *newNode; //pointer to create a node
 bool found;
 newNode = new nodeType<Type>; //create the node
 newNode->info = insertItem; //store the new item in the node
 newNode->next = NULL;
 newNode->back = NULL;
 if(!rst == NULL) //if the list is empty, newNode is
 //the only node
 {
 !rst = newNode;
 last = newNode;
 count++;
 }
 else
 {
 found = false;
 current = !rst;
 while (current != NULL && !found) //search the list
 if (current->info >= insertItem)
 found = true;
 else
 {
 trailCurrent = current;
 current = current->next;
 }
 if (current == !rst) //insert newNode before !rst
 {
 !rst->back = newNode;
 newNode->next = !rst;
 !rst = newNode;
 count++;
 }
 else
 {
 //insert newNode between trailCurrent and current
 if (current != NULL)
 {
 trailCurrent->next = newNode;
 newNode->back = trailCurrent;
 newNode->next = current;
 current->back = newNode;
 }
 else
 {
 trailCurrent->next = newNode;
 newNode->back = trailCurrent;
 last = newNode;
 }
 count++;
 }//end else
 }//end else
}//end insert
template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type& deleteItem)
{
 nodeType<Type> *current; //pointer to traverse the list
 nodeType<Type> *trailCurrent; //pointer just before current
 bool found;
 if (!rst == NULL)
 cout << "Cannot delete from an empty list." << endl;
 else if (!rst->info == deleteItem) //node to be deleted is
 //the !rst node
 {
 current = !rst;
 !rst = !rst->next;
 if (!rst != NULL)
 !rst->back = NULL;
 else
 last = NULL;
 count--;
 delete current;
 }
 else
 {
 found = false;
 current = !rst;
 while (current != NULL && !found) //search the list
 if (current->info >= deleteItem)
 found = true;
 else
 current = current->next;
 if (current == NULL)
 cout << "The item to be deleted is not in "
 << "the list." << endl;
 else if (current->info == deleteItem) //check for
 //equality
 {
 trailCurrent = current->back;
 trailCurrent->next = current->next;
 if (current->next != NULL)
 current->next->back = trailCurrent;
 if (current == last)
 last = trailCurrent;
 count--;
 delete current;
 }
 else
 cout << "The item to be deleted is not in list."
 << endl;
 }//end else
}//end deleteNode
template<class Type>
void doublyLinkedList<Type>::copyList(const doublyLinkedList<Type>& otherList)
{
 nodeType<Type> *newNode; //pointer to create a node
 nodeType<Type> *current; //pointer to traverse the list
 if(!rst != NULL) //if the list is nonempty, make it empty
 destroy();
 if(otherList.!rst == NULL) //otherList is empty
 {
 !rst = NULL;
 last = NULL;
 count = 0;
 }
 else
 {
 current = otherList.!rst; //current points to the
 //list to be copied.
 count = otherList.count;
 //copy the !rst node
 !rst = new nodeType<Type>; //create the node
 !rst->info = current->info; //copy the info
 !rst->next = NULL;
 !rst->back = NULL;
 last = !rst;
 current = current->next;
 //copy the remaining list
 while (current != NULL)
 {
 newNode = new nodeType<Type>; //create the node
 newNode->info = current->info;
 newNode->next = NULL;
 newNode->back = last;
 last->next = newNode;
 last = newNode;
 current = current->next;
 }//end while
 }//end else
}//end copyList
template<class Type>
doublyLinkedList<Type>::doublyLinkedList(const doublyLinkedList<Type>& otherList)
{
 !rst = NULL;
 copyList(otherList);
}
template<class Type>
const doublyLinkedList<Type>& doublyLinkedList<Type>::operator=
 (const doublyLinkedList<Type>& otherList)
{
 if (this != &otherList)
 {
 copyList(otherList);
 }
 return *this;
}
template<class Type>
doublyLinkedList<Type>::~doublyLinkedList()
{
 destroy();
}
#endif