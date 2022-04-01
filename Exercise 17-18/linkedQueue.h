//Header !le linkedQueue.h
#ifndef H_linkedQueue
#define H_linkedQueue
#include <iostream>
#include <cassert>
#include "queueADT.h"
using namespace std;
//De!nition of the node
template <class Type>
struct nodeType {
 Type info;
 nodeType<Type> *link;
};
template <class Type>
class linkedQueueType: public queueADT<Type> {
public:
 const linkedQueueType<Type>& operator=
 (const linkedQueueType<Type>&);
 //Overload the assignment operator.
 bool isEmptyQueue() const;
 bool isFullQueue() const;
 void initializeQueue();
 Type front() const;
 Type back() const;
 void addQueue(const Type& queueElement);
 void deleteQueue();
 linkedQueueType();
 linkedQueueType(const linkedQueueType<Type>& otherQueue);
 //Copy constructor
 ~linkedQueueType();
 //Destructor
private:
 nodeType<Type> *queueFront; //pointer to the front of
 //the queue
 nodeType<Type> *queueRear; //pointer to the rear of
 //the queue
};
template<class Type>
linkedQueueType<Type>::linkedQueueType() {
 queueFront = NULL; //set front to null
 queueRear = NULL; //set rear to null
} //end default constructor
template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const {
 return(queueFront == NULL);
} //end
template<class Type>
bool linkedQueueType<Type>::isFullQueue() const {
 return false;
} //end isFullQueue
template <class Type>
void linkedQueueType<Type>::initializeQueue() {
 nodeType<Type> *temp;
 while (queueFront!= NULL) //while there are elements left
 //in the queue
 {
 temp = queueFront; //set temp to point to the
 //current node
 queueFront = queueFront->link; //advance !rst to
 //the next node
 delete temp; //deallocate memory occupied by temp
 }
 queueRear = NULL; //set rear to NULL
} //end initializeQueue
template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement) {
 nodeType<Type> *newNode;
 newNode = new nodeType<Type>; //create the node
 newNode->info = newElement; //store the info
 newNode->link = NULL; //initialize the link !eld to NULL
 if (queueFront == NULL) //if initially the queue is empty
 {
 queueFront = newNode;
 queueRear = newNode;
 }
 else //add newNode at the end
 {
 queueRear->link = newNode;
 queueRear = queueRear->link;
 }
}//end addQueue
template <class Type>
Type linkedQueueType<Type>::front() const {
 assert(queueFront != NULL);
 return queueFront->info;
} //end front
template <class Type>
Type linkedQueueType<Type>::back() const {
 assert(queueRear!= NULL);
 return queueRear->info;
} //end back
template <class Type>
void linkedQueueType<Type>::deleteQueue() {
 nodeType<Type> *temp;
 if (!isEmptyQueue()){
 temp = queueFront; //make temp point to the
 //!rst node
 queueFront = queueFront->link; //advance queueFront
 delete temp; //delete the !rst node
 if (queueFront == NULL) //if after deletion the
 //queue is empty
 queueRear = NULL; //set queueRear to NULL
 }
 else
 cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue
template <class Type>
linkedQueueType<Type>::~linkedQueueType() {
} //end destructor
template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
 (const linkedQueueType<Type>& otherQueue) {
} //end assignment operator
 //copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType
 (const linkedQueueType<Type>& otherQueue) {
}//end copy constructor
#endif
