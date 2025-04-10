#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
      Node* front;
      Node* rear;
      int max;
      int size;
    
    public:
      Queue(int m)
      {
        front = nullptr;
        rear = nullptr;
        max = m;
        size = 0;
      }

      bool isempty()
      {
        return front == nullptr;
      }

      bool isfull() 
      {
        return size == max;
      }

      void enqueue(int value)
      {
        if(isfull())
        {
           cout<<"Queue Overflow!"<<endl;
           return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if(front == nullptr)
        {
            front = newNode;
            rear = newNode;
            size++;
        }
        else 
        {
            rear->next = newNode;
            rear = newNode;
            size++;
        }
        cout<<"Element "<<value<<" added Successfully!"<<endl;
      }

      int dequeue()
      {
        if(isempty())
        {
            cout<<"Queue Underflow!"<<endl;
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        cout<<"Element "<<value<<" removed Successfully!"<<endl;
        return value;
      }

      void peek()
      {
        if(isempty())
        {
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<"Front element is: "<<front->data<<endl;
      }

      void display()
      {
        if(isempty())
        {
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Node* temp = front;
        cout<<"Queue elements: ";
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
  cout<<"Enter the maximum size of queue: ";
  cin>>max;

  Queue q(max);
  int ch, value;

  do 
  {
   cout<<"\nQueue Operations:\n";
   cout<<"1. Enqueue\n";
   cout<<"2. Dequeue\n";
   cout<<"3. Peek\n";
   cout<<"4. Display\n";
   cout<<"5. Exit\n";
   cout<<"Enter your choice: ";
   cin>>ch;

   switch(ch)
   {
     case 1:
       cout<<"Enter an integer to add: ";
       cin>>value;
       q.enqueue(value);
       break;
     case 2:
       q.dequeue();
       break;
     case 3:
       q.peek();
       break;
     case 4:
       q.display();
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