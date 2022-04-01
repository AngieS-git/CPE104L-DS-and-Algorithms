#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

struct node{
  float data;
  node *next;
};

class trapLinkedList
{
  node* head; //head pointer

  public:
    //initialize head pointer
    trapLinkedList()
    {
      head = NULL;
    }

    float f(float x)
    {
      return 3*x+(pow(x,2));
    }

    float F(float x)
    {
      return ((pow(x,2))*(2*x+9))/6;
    }

    void trapArea(float val)
    {
      node* new_node = new node;
      new_node->data = val;
      new_node->next = NULL;

      if(head == NULL)
        head = new_node;
      else{
        new_node->next = head;
        head = new_node;
      }
    }

    void reverseVals()
    {
      node* current = head;
      node *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }
        head = prev;
    }

    void displayVal()
    {
      int counter = 1;
      node* temp = head;
      while(temp != NULL)
      {
        cout<< "Trapezoid area "<< counter++ << " = " << fixed << setprecision(4) << temp->data<<" units squared."<<endl;
        temp = temp->next;
      }
      cout<<endl;
    }

    float sumOfVals()
    {
      float total = 0;
      node *current = head;
      while (current!=NULL){
        total += current->data;
        current = current->next;
      }
      return total;
    }
};

int main()
{
  float a, b;
  int numOftrapz;

  trapLinkedList trapzObj;

  cout<<"Enter the value of a: ";
  cin>>a;
  cout<<"Enter the value of b: ";
  cin>>b;
  cout<<"Specify the number of trapezoids: ";
  cin>>numOftrapz;
  cout<<endl;

  float integral = trapzObj.F(b) - trapzObj.F(a);

  float h = (float)((b-a)/numOftrapz);

  float sum_trapz = 0;

  while(a<=b)
  {
    float func_ai = a;
    float func_bi = a + h;
    float fai = trapzObj.f(func_ai);
    float fbi = trapzObj.f(func_bi);
    float val = ((fai + fbi)/2)*h;

    trapzObj.trapArea(val);

    a = func_bi;
  }

  trapzObj.reverseVals();
  trapzObj.displayVal();

  cout<<"\n\nThe area using trapezoid method = "<<trapzObj.sumOfVals()<<" units Squared.\n";
  cout<<"The area using integral calculus = "<< integral<< " units Squared."<<endl;


  float rel_err = ((integral - trapzObj.sumOfVals())/integral)*100;
  cout<<"Percent Error: "<<abs(rel_err)<< "%"<<endl;


  return 0;
}
