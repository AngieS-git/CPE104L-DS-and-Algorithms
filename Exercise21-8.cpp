#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Face values
const string faceValues[] = { "One", "Two", "Three", "Four", "Five",
 "Six", "Seven", "Eight", "Nine", "Ten",
 "Jack", "Queen", "King" };
// suit values
const string suitValues[] = { "Spade", "Club", "Diamond", "Heart" };
void Tips(vector<string> deck, const string &guess)
{
 // tip 1
 vector<string> myVector=deck;
 random_shuffle(myVector.begin(), myVector.end());
 // tip 2
 string a;
 size_t found;
 // Randomly select one card.
 a = myVector[rand()%13];
 // check the select is same as that of guess card
 found = a.find(guess);
 
 if (found == string::npos){
 cout << "You lose!" << endl;
 }
 else
 {
 cout << "You won!" << endl;
}
}
// printMenu() method to display menu to users
void printMenu()
{
 cout << "\nTo play the game choose one of the following :" << endl;
 cout << " 1 : To guess the face value only." << endl;
 cout << " 2 : To guess the suit value only." << endl;
 cout << " 3 : To guess the both the face and suit." << endl;
 cout << " 9 : To end the game." << endl << endl;
 cout << "Enter your choice: ";
}
// Driver code
int main() {
 vector<string> deck;
 // create the deck of cards
 for (const auto & i : faceValues)
 for (const auto & j : suitValues)
 
 deck.push_back(i + " of " + j);
 int choice = 0;
 string guess;
 
 // display menu
 printMenu();
 cin >> choice;
 // while loop until user does not exit the program
 while (choice != 9)
 {
 if(choice==1)
 {
 cout<<"Guess the face value : ";
 cin>>guess;
 Tips(deck, guess);
 }
 else if(choice==2)
 {
 cout<<"Guess the suit value : ";
 cin>>guess;
 Tips(deck, guess);
 }
 else if(choice==3)
 {
 cout<<"Guess the face value : ";
 cin>>guess;
 guess += " of ";
 string str;
 cout<<"Guess the suit value : ";
 cin>>str;
 guess += str;
 Tips(deck, guess);
 }
 printMenu();
 cin >> choice;
 }
 return 0;
}