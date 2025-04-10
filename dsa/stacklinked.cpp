#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class Stack {
  private:
     Node* top;
     int max;
     int size;

  public:
     Stack(int m)
     {
       top = nullptr;
       max = m;
       size = 0;
     }

     bool isempty()
     {
       return top == nullptr;
     }

     bool isfull()
     {
      return size>=max;
     }

     void push(int value)
     {
      if(isfull())
      {
        cout<<"Stack overflow!"<<endl;
        return;
      }
      Node* newNode = new Node();
      newNode->data = value;
      newNode->next = top;
      top = newNode;
      size++;
      cout<<"Element "<<value<<" pushed Successfully!"<<endl;
     }

     void pop()
     {
      if(isempty())
      {
        cout<<"Stack Underflow!"<<endl;
        return;
      }
      cout<<"Element "<<top->data<<" popped Successfully!"<<endl;
      Node* temp = top;
      top = top->next;
      delete temp;
      size--;
     }

     void peek()
     {
      if(isempty())
      {
        cout<<"Stack is empty!"<<endl;
        return;
      }
      cout<<"Top element is: "<<top->data<<endl;
     }

     void display()
     {
      if(isempty())
      {
        cout<<"Stack is empty!"<<endl;
        return;
      }
      Node* temp = top;
      cout<<"Stack elements: ";
      while(temp!=nullptr)
      {
        cout<<temp->data<<" ";
        temp = temp->next;
      }
      cout<<"\n";
     }
};

int main()
{
  int max;
  cout<<"Enter the maximum size of the stack: ";
  cin>>max;

  Stack s(max);
  int ch, value;

  do 
  {
   cout<<"\nStack Operations:\n";
   cout<<"1. Push\n";
   cout<<"2. Pop\n";
   cout<<"3. Peek\n";
   cout<<"4. Display\n";
   cout<<"5. Exit\n";
   cout<<"Enter your choice: ";
   cin>>ch;

   switch(ch)
   {
     case 1:
       cout<<"Enter an integer to push: ";
       cin>>value;
       s.push(value);
       break;
     case 2:
       s.pop();
       break;
     case 3:
       s.peek();
       break;
     case 4:
       s.display();
       break;
     case 5:
       cout<<"Exiting Program.\n";
       break;
     default:
       cout<<"Invalid choice!\n";
   }
  }while(ch!=5);
  return 0;
}