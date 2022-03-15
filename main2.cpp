#include <iostream> 
#include "circularLinkedList.h" 
using namespace std; 

void testCopyConstructor(circularLinkedList<int> list);
int main() 
{
    circularLinkedList<int> list1; 
    int num; 
    cout << "Enter numbers ending " << "with -999." << endl; 
    cin >> num; 
    while (num != -999) 
    { 
    list1.insertNode(num); 
    cin >> num; 
    } 
    cout << endl; 

    cout << "List 1: "; 
    list1.print(); 
    cout<<"Length List 1: "<<   list1.length();
  

    cout << endl; 

    cout << "Enter the number to be searched: ";
    cin >> num; 
    cout << endl; 

    if(list1.search(num)){
        cout<< num<< " found in the list\n";
    };

    cout<<"Enter the number to be deleted: ";
    cin>>num;
    list1.deleteNode(num);
    cout << endl;
    cout << "After deleting " << num << ", List 1: "; 
    list1.print(); 
    cout << endl;
    cout<<"Length List 1: "<< list1.length();


    return 0; 
} 
void testCopyConstructor(circularLinkedList<int> list)
  {
  }
