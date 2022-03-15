#ifndef H_CircularOrderedListType
#define H_CircularOrderedListType
#include "circularLinkedList.h"
#include <iostream>
#include <string>
using namespace std;
template <class Type>
class circularOrderedLinkedList: public circularLinkedListType<Type>
{
public:
 bool search(const Type& searchItem) const;
 void insert(const Type& newItem);
 void insertFirst(const Type& newItem);
 void insertLast(const Type& newItem);
 void deleteNode(const Type& deleteItem);
};
template <class Type>
bool circularOrderedLinkedList<Type>::search(const Type& searchItem) const
{
 bool found = false;
 nodeType<Type> *current;
 current = !first;
 while(current != last->link && !found)
 if (current->info >= searchItem)
 found = true;
 else
 current = current->link;
 if (found)
 found = (current->info == searchItem);
 return found;
}
template <class Type>
void circularOrderedLinkedList<Type>::insert(const Type& newItem)
{
 nodeType<Type> *current;
 nodeType<Type> *trailCurrent;
 nodeType<Type> *newNode;
 bool found;
 newNode = new nodeType<Type>;
 newNode->info = newItem;
 newNode->link = NULL; 
 if (!rst == NULL)
 {
 !rst = newNode;
 last = newNode;
 last->link = !first;
 count++;
 }
 else
 {
 current = !first;
 found = false;
 int currentCount = 0;
 while(currentCount < count && !found)
 {
 if(current->info >= newItem)
 found = true;
 else
 {
 trailCurrent = current;
 current = current->link;
 currentCount++;
 }
 }
 if(currentCount == 0)
 {
 newNode->link = !rst; 
 !rst = newNode;
 last->link = !rst;
 count++;
 }
 else 
 {
 trailCurrent->link = newNode;
 newNode->link = current;
 if(currentCount == count)
 {
 last = newNode;
 last->link = !first;
 }
 count++;
 }
 }
}
template<class Type>
void circularOrderedLinkedList<Type>::insertFirst(const Type& newItem)
{
 insert(newItem);
}
template<class Type>
void circularOrderedLinkedList<Type>::insertLast(const Type& newItem)
{
 insert(newItem);
}
template<class Type>
void circularOrderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
 nodeType<Type> *current;
 nodeType<Type> *trailCurrent;
 bool found;
 if (!rst == NULL)
 cout << "Cannot delete from an empty list." << endl;
 else
 {
 current = !first;
 found = false;
 int currentCount = 0;
 while (currentCount < count && !found)
 {
 if (current->info >= deleteItem)
 found = true;
 else
 {
 trailCurrent = current;
 current = current->link;
 currentCount++;
 }
 }
 if (currentCount == count)
 cout << "The item to be deleted is not in the " << "list." << endl;
 else
 if (current->info == deleteItem)
 {
 if (!first == current) 
 {
 !rst = !first->link;
 
 if (currentCount = 0)
 last = NULL;
 delete current;
 }
 else 
 {
 trailCurrent->link = current->link;
 if (current == last)
 {
 last = trailCurrent;
 last->link = !first;
 }
 delete current;
 }
 count--;
 }
 else 
 cout << "The item to be deleted is not in the " << "list." << endl;
 }
}
#endif