#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

void testCopyConstructor(doublyLinkedList<int> list);
  int main()
  {
  doublyLinkedList<int> intList, temp;
  int num;
  cout << "Enter a list of positive integers ending "
  << "with -999: " << endl;
  cin >> num;

  while(num != -999)
    {
      intList.insert(num);
      cin >> num;
    }

      cout << endl;
      cout << "List in ascending order: ";
      intList.print();
      cout << '\n';

      cout << "List in descending order: ";
      intList.reversePrint();
      cout << '\n';

      cout << "Enter item to be deleted: ";
      cin >> num;
      cout << '\n';
      intList.deleteNode(num);

      cout << "List after deleting " << num << " : ";
      intList.print();
      cout << '\n';

      cout << "Enter item to be searched: ";
      cin >> num;
      cout << '\n';
      
      if(intList.search(num))
      cout << num << " found in the list.\n";
      else
      cout << num << " is not in the list." << endl;
      cout << "********Testing copy constructor***********\n" ;
      testCopyConstructor(intList);
      cout << "intList: ";
      intList.print();
      cout << '\n';
      temp.destroy();

      cout << "********Testing assignment operator***********\n";
      temp = intList;
      cout << "temp: ";
      intList.print();
      cout << '\n';
      return 0;
  }

  void testCopyConstructor(doublyLinkedList<int> list)
  {
  }
