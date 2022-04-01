#include<iostream>
#include<iomanip>

using namespace std;

struct node{
  int data;
  node *next;
};

class trapLinkedList
{
  node* head; //head pointer

  public:
    int counter = 0;
    //initialize head pointer
    trapLinkedList()
    {
      head = NULL;
    }

    float f(float x)
    {
      return 3*x+(x*x);
    }

    float F(float x)
    {
      return ((x*x)*(2*x+9))/6;
    }

    void trapArea(float fai, float fbi, float h)
    {
      node* new_node = new node;
      new_node->data = ((fai + fbi)/2)*(h);
      new_node->next = NULL;

      if(head == NULL)
        head = new_node;
      else{
        new_node->next = head;
        head = new_node;
      }
    }

    void displayVal()
    {
      node* temp = head;
      while(temp != NULL)
      {
        cout<< "Trapezoid area "<< counter++ << " = " << fixed << setprecision(4) << temp->data<<" units squared."<<endl;
        temp = temp->next;
      }
      cout<<endl;
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

    trapzObj.trapArea(func_ai,func_ai,h);

    a = func_bi;
  }

  trapzObj.displayVal();


  return 0;
}
